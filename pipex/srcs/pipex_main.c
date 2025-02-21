/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/21 14:03:13 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	int		pipe_fds[2];
	int		i;

	i = -1;
	if (argc != 5 || !*argv[2] || !*argv[3])
		clean_pipes_exit(NULL, 1);
	pipex_init(&pipex, argv, envp);
	if (pipe(pipe_fds) == -1)
		clean_pipes_exit(pipex, 7);
	pipex->fd[0][1] = pipe_fds[1]; // write from 1
	pipex->fd[1][0] = pipe_fds[0]; // read to 2
	child_process((t_crossfd){pipex->fd[0][0], pipex->fd[0][1], pipex->fd[1][0],
		pipex->fd[1][1]}, pipex->paths[0], pipex->comd[0], pipex);
	child_process((t_crossfd){pipex->fd[1][0], pipex->fd[1][1], pipex->fd[0][0],
		pipex->fd[0][1]}, pipex->paths[1], pipex->comd[1], pipex);
	wait(NULL);
	// ft_printf("\n_____________\n\nmy final message. goodbye.\n");
	close(pipex->fd[1][0]);
	close(pipex->fd[1][1]);
	close(pipex->fd[0][0]);
	close(pipex->fd[0][1]);
	clean_pipes_exit(pipex, 10);
}

void	pipex_init(t_pipe **pipex, char **av, char **env)
{
	int	i;

	// ft_printf("find the seg\n");
	*pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		clean_pipes_exit(*pipex, 2);
	(*pipex)->fd[0][0] = open(av[1], O_RDONLY);
	(*pipex)->fd[1][1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*pipex)->fd[0][0] == -1 || (*pipex)->fd[1][1] == -1)
		clean_pipes_exit(*pipex, 3);
	(*pipex)->comd[0] = ft_split(av[2], ' ');
	(*pipex)->comd[1] = ft_split(av[3], ' ');
	if (!(*pipex)->comd[0] || !(*pipex)->comd[1])
		clean_pipes_exit(*pipex, 4);
	i = -1;
	(*pipex)->envp = NULL;
	while (env[++i] && !(*pipex)->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			(*pipex)->envp = ft_split(env[i] + 5, ':');
	if (!(*pipex)->envp)
		clean_pipes_exit(*pipex, 5);
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
				clean_pipes_exit(pipex, 6);
			result = access(temp_2, F_OK);
			if (!result || !pipex->envp[i + 1])
				pipex->paths[j] = ft_strdup(temp_2);
			free(temp_2);
		}
	}
}

void	child_process(t_crossfd fd, char *path, char **cmd, t_pipe *pipex)
{
	int	id;

	id = fork();
	if (id == -1)
		clean_pipes_exit(pipex, 8);
	if (id == 0)
	{
		// ft_printf("\n_____________\n\nchild\n");
		close(fd.out_read);
		close(fd.out_write);
		dup2(fd.in_read, STDIN_FILENO);
		close(fd.in_read);
		dup2(fd.in_write, STDOUT_FILENO);
		close(fd.in_write);
		if (execve(path, cmd, pipex->env) == -1)
			clean_pipes_exit(pipex, 9);
	}
}
