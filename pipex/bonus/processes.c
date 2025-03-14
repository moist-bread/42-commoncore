/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:30:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/14 17:38:40 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	create_pipe(t_pipe_data *pipex, int i)
{
	int	pipe_fd[2];

	ft_printf(BLU "-- create pipe [beggining]\n" DEF);
	if (pipe(pipe_fd) == -1)
		pipex_free_exit(pipex, 13, 13);
	pipex->fd[i + 1][0] = pipe_fd[0];
	pipex->fd[i][1] = pipe_fd[1];
	ft_printf(BLU "-- create pipe [ending]\n\n" DEF);
}

void	create_child_pro(t_pipe_data *pipex, int i)
{
	ft_printf(BLU "-- create child pro [beggining]\n" DEF);
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		pipex_free_exit(pipex, 14, 14);
	if (pipex->pid[i] == 0)
	{
		process_setup(pipex, i);
		if (execve(pipex->paths[i], pipex->cmd[i], pipex->env) == -1)
			pipex_free_exit(pipex, 15, 127);
	}
	ft_printf(BLU "-- create child pro [ending]\n\n" DEF);
}

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

void	multi_process_waiting(t_pipe_data *pipex, int *status)
{
	int	i;
	int	w_pid;
	int	exit_status;

	i = -1;
	w_pid = pipex->pid[0];
	while (++i < pipex->count && w_pid != pipex->pid[pipex->count - 1])
		w_pid = wait(&exit_status);
	while (++i < pipex->count && w_pid == pipex->pid[pipex->count - 1])
		wait(NULL);
	if (WIFEXITED(exit_status))
		*status = WEXITSTATUS(exit_status);
}
