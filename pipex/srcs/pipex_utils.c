/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:53:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/03 19:42:22 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_init(t_pipe **pipex, char **av, char **env)
{
	int	i;

	*pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		clean_pipes_exit(*pipex, 2, 2);
	(*pipex)->fd[0][0] = open(av[1], O_RDONLY);
	(*pipex)->fd[1][1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*pipex)->fd[0][0] == -1)
		perror(YEL "infile open failure" DEF);
	if ((*pipex)->fd[1][1] == -1)
		clean_pipes_exit(*pipex, 3, 3);
	(*pipex)->comd[0] = command_separator(av[2]);
	(*pipex)->comd[1] = command_separator(av[3]);
	if (!(*pipex)->comd[0] || !(*pipex)->comd[1])
		clean_pipes_exit(*pipex, 4, 4);
	i = -1;
	(*pipex)->envp = NULL;
	while (env[++i] && !(*pipex)->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			(*pipex)->envp = ft_split(env[i] + 5, ':');
	if (!(*pipex)->envp)
		clean_pipes_exit(*pipex, 5, 5);
	find_paths(*pipex, 2);
	(*pipex)->env = env;
}

void	find_paths(t_pipe *pipex, int n)
{
	int		i;
	int		j;
	int		result;
	char	*path;

	j = -1;
	while (++j < n)
	{
		i = -1;
		result = 1;
		while (pipex->envp[++i] && result)
		{
			path = make_path(pipex, j, i);
			result = access(path, F_OK);
			if (!result)
				pipex->paths[j] = ft_strdup(path);
			else if (!pipex->envp[i + 1])
				pipex->paths[j] = ft_strdup(pipex->comd[j][0]);
			free(path);
		}
	}
}

char	*make_path(t_pipe *pipex, int j, int i)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(pipex->envp[i], "/");
	path = ft_strjoin(temp, pipex->comd[j][0]);
	if (temp)
		free(temp);
	if (!path)
		clean_pipes_exit(pipex, 6, 6);
	return (path);
}

void	child_process(t_crossfd fd, t_pipe *pipex, int i)
{
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
		clean_pipes_exit(pipex, 8, 8);
	if (pipex->pid[i] == 0)
	{
		if (fd.out_read != -1)
			close(fd.out_read);
		if (fd.out_write != -1)
			close(fd.out_write);
		dup2(fd.in_read, STDIN_FILENO);
		if (fd.in_read != -1)
			close(fd.in_read);
		dup2(fd.in_write, STDOUT_FILENO);
		if (fd.in_write != -1)
			close(fd.in_write);
		if (execve(pipex->paths[i], pipex->comd[i], pipex->env) == -1)
			clean_pipes_exit(pipex, 9, 127);
	}
}

void	process_waiting(t_pipe *pipex, int *status)
{
	int	w_pid;
	int	exit_status;

	w_pid = wait(&exit_status);
	if (w_pid == pipex->pid[0])
		wait(&exit_status);
	else
		wait(NULL);
	if (WIFEXITED(exit_status))
		*status = WEXITSTATUS(exit_status);
}
