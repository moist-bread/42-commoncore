/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:30:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 16:49:45 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/// @brief creates a here_doc in which it will write the next line
/// from STDOUT until it encounters the LIMITER string
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param limiter LIMITER string
void	here_doc_handler(t_pipe_data *pipex, char *limiter)
{
	char	*line;

	if (pipex->fd[0][0] == -1)
		pipex_free_exit(pipex, 12, 12);
	while (1)
	{
		line = get_next_line(1);
		if (line)
		{
			ft_putstr_fd(line, pipex->fd[0][0]);
			if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
				break ;
			free(line);
		}
	}
	if (line)
		free(line);
	close(pipex->fd[0][0]);
	pipex->fd[0][0] = open("here_doc", O_RDONLY);
	if (pipex->fd[0][0] == -1)
		pipex_free_exit(pipex, 12, 12);
}

/// @brief creates a pipe and stores the resulting fds
/// in the PIPEX struct according to i  
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param i index of the current cmd to be executed
void	create_pipe(t_pipe_data *pipex, int i)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		pipex_free_exit(pipex, 13, 13);
	pipex->fd[i + 1][0] = pipe_fd[0];
	pipex->fd[i][1] = pipe_fd[1];
}

/// @brief creates a fork and makes it execute a cmd according to i
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param i index of the current cmd to be executed
void	create_child_pro(t_pipe_data *pipex, int i)
{
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		pipex_free_exit(pipex, 14, 14);
	if (pipex->pid[i] == 0)
	{
		process_setup(pipex, i);
		if (execve(pipex->paths[i], pipex->cmd[i], pipex->env) == -1)
			pipex_free_exit(pipex, 15, 127);
	}
}

/// @brief closes and dups fds according to i to set up for execve
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param i index of the current cmd to be executed
void	process_setup(t_pipe_data *pipex, int i)
{
	int	add;

	if (i % 2 == 0 && i + 1 != pipex->count)
		add = 1;
	else
		add = -1;
	if (pipex->fd[i + add][0] != -1)
		close(pipex->fd[i + add][0]);
	if (pipex->fd[i + add][1] != -1)
		close(pipex->fd[i + add][1]);
	dup2(pipex->fd[i][0], STDIN_FILENO);
	if (pipex->fd[i][0] != -1)
		close(pipex->fd[i][0]);
	else
	{
		close(0);
		close(pipex->fd[i][1]);
		pipex_free_exit(pipex, 16, 127);
	}
	dup2(pipex->fd[i][1], STDOUT_FILENO);
	close_all_fds(pipex);
}

/// @brief waits for all forked child processes to finish
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param status changes to the exit status of the last called process
void	multi_process_waiting(t_pipe_data *pipex, int *status)
{
	int	i;
	int	w_pid;
	int	exit_status;

	i = 0;
	w_pid = pipex->pid[0];
	while (i < pipex->count && w_pid != pipex->pid[pipex->count - 1])
	{
		w_pid = wait(&exit_status);
		i++;
	}
	while (i < pipex->count && w_pid == pipex->pid[pipex->count - 1])
	{
		wait(NULL);
		i++;
	}
	if (WIFEXITED(exit_status))
		*status = WEXITSTATUS(exit_status);
}
