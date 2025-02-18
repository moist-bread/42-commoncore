/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/18 20:01:20 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	int		pipe_fds[2];
	int		id;
	int		i;

	i = -1;
	if (argc != 5)
		clean_pipes_exit(NULL, 1);
	pipex_init(&pipex, argv, envp);
	// print_pipe(pipex);
	if (pipe(pipe_fds) == -1)
		return (perror(YEL "pipe unsuccessfull" DEF), 5);
	else
		ft_printf("\n_____________\n\n- pipe opened -\n");
	pipex->fd[1][0] = pipe_fds[0]; // read from 2
	pipex->fd[0][1] = pipe_fds[1]; // write to 1
	print_pipe(pipex);
	id = fork(); //  check for fork failure
	if (id == 0)
	{
		ft_printf("\n_____________\n\nchild_1\n");
		close(pipex->fd[1][0]);
		ft_printf("dupping STDOUT\n");
		dup2(pipex->fd[0][0], STDIN_FILENO);
		close(pipex->fd[0][0]);
		dup2(pipex->fd[0][1], STDOUT_FILENO);
		close(pipex->fd[0][1]);
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
	}
	// wait(NULL);
	id = fork();
	if (id == 0)
	{
		ft_printf("\n_____________\n\nchild_2\n");
		close(pipex->fd[0][1]);
		ft_printf("dupping STDIN\n");
		dup2(pipex->fd[1][0], STDIN_FILENO);
		dup2(pipex->fd[1][1], STDOUT_FILENO);
		close(pipex->fd[1][0]);
		close(pipex->fd[1][1]);
		if (execve(pipex->paths[1], pipex->comd[1], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
	}
	wait(NULL);
	ft_printf("\n_____________\n\n");
	ft_printf("parent\n");
	ft_printf("closing message");
	close(pipex->fd[1][0]);
	close(pipex->fd[1][1]);
	ft_printf("\n_____________\n\n");
	clean_pipes_exit(pipex, 10);
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
}

void	find_paths(t_pipe *pipex, char **env, int n)
{
	int	i;
	int	j;
	int	result;
	char *temp_1;
	char *temp_2;

	i = -1;
	pipex->envp = NULL;
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
			temp_1 = ft_strjoin(pipex->envp[i], "/");
			temp_2 = ft_strjoin(temp_1, pipex->comd[j][0]);
			result = access(temp_2, F_OK);
			free (temp_1);
			if (!result)
				pipex->paths[j] = ft_strdup(temp_2);
			free (temp_2);
		}
	}
}
