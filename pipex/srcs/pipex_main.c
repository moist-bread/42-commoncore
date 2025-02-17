/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/17 15:38:27 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	int		pipe_fds[2];
	int		id;
	int		i;

	// int		result;
	i = -1;
	if (argc != 5)
		return (1);
	pipex_init(&pipex, argv, envp);
	print_pipe(pipex);
	id = fork();
	if (id == 0)
	{
		close(pipex->fd[1][1]);
		close(pipex->fd[1][0]);
		ft_printf("\n_____________\n\nchild_1\n");
		ft_printf("executing command\n\n");
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
		ft_printf("child is dead");
	}
	wait(NULL);
	if (pipe(pipe_fds) == -1)
		return (perror(YEL "pipe unsuccessfull" DEF), 5);
	else
		ft_printf("\n_____________\n\n- pipe opened -\n");
	pipex->fd[1][0] = pipe_fds[0]; // read from 2
	pipex->fd[0][1] = pipe_fds[1]; // write to 1
	print_pipe(pipex);
	id = fork();
	if (id == 0)
	{
		ft_printf("\n_____________\n\nchild_2\n");
		close(pipex->fd[1][0]);
		ft_printf("dupping STDOUT\n");
		dup2(pipex->fd[1][1], STDOUT_FILENO);
		close(pipex->fd[1][1]);
		ft_printf("fd has been dupped\n\n");
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
		ft_printf("child is dead");
	}
	wait(NULL);
	id = fork();
	if (id == 0)
	{
		ft_printf("\n_____________\n\nchild_3\n");
		close(pipex->fd[1][1]);
		ft_printf("dupping STDIN\n");
		dup2(pipex->fd[1][0], STDIN_FILENO); // the fd of the pipe
		close(pipex->fd[1][0]);
		ft_printf("fd has been dupped\n\n");
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
		ft_printf("child is dead");
	}
	wait(NULL);
	ft_printf("\n_____________\n\n");
	ft_printf("parent\n");
	ft_printf("not doing anything yet");
	close(pipex->fd[1][0]);
	close(pipex->fd[1][1]);
	ft_printf("\n_____________\n\n");
}

// exit meanings
// 1: not enough input
// 2: file 1 doesnt exists
// 3: malloc issues
// 4: command didnt execute
// 5: pipe failure
// 6: open failed

void	pipex_init(t_pipe **pipex, char **av, char **env)
{
	// ft_printf("find the seg\n");
	// return (perror(YEL "no file found" DEF));
	*pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		clean_pipes_exit(*pipex, 3);
	(*pipex)->fd[0][0] = open(av[1], O_RDONLY);
	// read from 1
	(*pipex)->fd[1][1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	// write to 2
	if ((*pipex)->fd[0][0] == -1 || (*pipex)->fd[1][1] == -1)
		clean_pipes_exit(*pipex, 6);
	(*pipex)->comd[0] = ft_split(av[2], ' ');
	(*pipex)->comd[1] = ft_split(av[3], ' ');
	if (!(*pipex)->comd[0] || !(*pipex)->comd[1])
		clean_pipes_exit(*pipex, 3);
	find_paths(*pipex, env, 2);
	(*pipex)->env = env;
	(*pipex)->ret = 0;
}

void	find_paths(t_pipe *pipex, char **env, int n)
{
	int	i;
	int	j;
	int	result;

	i = -1;
	while (env[++i] && !pipex->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			pipex->envp = ft_split(env[i] + 5, ':');
	if (!pipex->envp)
		clean_pipes_exit(pipex, 3);
	j = -1;
	while (++j < n)
	{
		i = -1;
		result = 1;
		while (pipex->envp[++i] && result)
		{
			result = access(ft_strjoin(ft_strjoin(pipex->envp[i], "/"),
						pipex->comd[j][0]), F_OK);
			if (!result)
				pipex->paths[j] = ft_strjoin(ft_strjoin(pipex->envp[i], "/"),
						pipex->comd[j][0]);
		}
	}
}

void	clean_pipes_exit(t_pipe *pipex, int status)
{
	(void)pipex;
	exit(status); // make it good
}

void	print_pipe(t_pipe *pipex)
{
	int	i;

	ft_printf("\npipex->fd[0][0]: %d\n", pipex->fd[0][0]);
	ft_printf("pipex->fd[0][1]: %d\n\n", pipex->fd[0][1]);
	ft_printf("pipex->fd[1][0]: %d\n", pipex->fd[1][0]);
	ft_printf("pipex->fd[1][1]: %d\n\n", pipex->fd[1][1]);
	i = -1;
	while (pipex->comd[0][++i])
		ft_printf("pipex->comd[0][i]: %s\n", pipex->comd[0][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->comd[1][++i])
		ft_printf("pipex->comd[1][i]: %s\n", pipex->comd[1][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->envp[++i])
		ft_printf("pipex->envp[i]: %s\n", pipex->envp[i]);
	ft_printf("\n");
	ft_printf("pipex->paths[0]: %s\n", pipex->paths[0]);
	ft_printf("pipex->paths[1]: %s\n\n", pipex->paths[1]);
	ft_printf("pipex->ret: %d\n", pipex->ret);
}
