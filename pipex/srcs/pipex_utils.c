/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:53:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/28 16:35:35 by rduro-pe         ###   ########.fr       */
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
	(*pipex)->comd[0] = ft_split(av[2], ' ');
	(*pipex)->comd[1] = ft_split(av[3], ' ');
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
	char	*temp_1;
	char	*temp_2;

	j = -1;
	while (++j < n)
	{
		i = -1;
		result = 1;
		while (pipex->envp[++i] && result)
		{
			temp_1 = ft_strjoin(pipex->envp[i], "/");
			temp_2 = ft_strjoin(temp_1, pipex->comd[j][0]);
			if (temp_1)
				free(temp_1);
			if (!temp_2)
				clean_pipes_exit(pipex, 6, 6);
			result = access(temp_2, F_OK);
			if (!result)
				pipex->paths[j] = ft_strdup(temp_2);
			else if (!pipex->envp[i + 1])
				pipex->paths[j] = ft_strdup(pipex->comd[j][0]);
			free(temp_2);
		}
	}
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
			clean_pipes_exit(pipex, 9, 127); // command didnt execute
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
