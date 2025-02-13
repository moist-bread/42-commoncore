/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/13 12:49:17 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	char	line[5];
	int		result;
	int		id;

	(void)line;
	(void)envp;
	if (argc != 5)
		return (1);
	result = access(argv[1], F_OK);
	ft_printf("%d (file 1)\n", result);
	if (result == -1)
		return (perror(YEL "no file found" DEF), 2);
	result = access(argv[4], F_OK);
	ft_printf("%d (file 2)\n\n", result);
	pipex_init(&pipex, argv);
	print_pipe(pipex);
	// if (pipe(pipex->fds) == -1)
	// 	return (perror(YEL "pipe unsuccessfull" DEF), 5);
	// else
	// 	ft_printf("\n_____________\n\n- pipe opened -");
	id = fork();
	if (id == 0)
	{
		close(pipex->fds[1]);
		close(pipex->fds[0]);
		ft_printf("\n_____________\n\nchild_1\n");
		// write(pipex->fds[1], "bruh", 5);
		// close(pipex->fds[1]);
		ft_printf("executing command\n\n");
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
		ft_printf("child is dead");
	}
	else
	{
		wait(NULL);
		id = fork();
	}
	if (id == 0)
	{
		ft_printf("\n_____________\n\nchild_2\n");
		close(pipex->fds[0]);
		ft_printf("dupping STDOUT\n");
		dup2(pipex->fds[1], STDOUT_FILENO);
		close(pipex->fds[1]);
		ft_printf("fd has been dupped\n\n");
		if (execve(pipex->paths[0], pipex->comd[0], pipex->env) == -1)
			return (perror(YEL "command didn't execute" DEF), 4);
		ft_printf("child is dead");
	}
	else
	{
		wait(NULL);
		ft_printf("\n_____________\n\n");
		// close(pipex->fds[1]);
		// read(pipex->fds[0], line, 5);
		// close(pipex->fds[0]);
		// ft_printf("\n%s\n\n", line);
		ft_printf("parent\n");
		ft_printf("not doing anything yet");
		close(pipex->fds[1]);
		close(pipex->fds[0]);
		ft_printf("\n_____________\n\n");
	}
}

// exit meanings
// 1: not enough input
// 2: file 1 doesnt exists
// 3: malloc issues
// 4: command didnt execute
// 5: pipe failure

void	pipex_init(t_pipe **pipex, char **av)
{
	char	*temp_1;
	char	*temp_2;

	// ft_printf("find the seg\n");
	*pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		return ;
	(*pipex)->temp = 0;
	(*pipex)->fds[0] = open(av[1], O_RDONLY);
	(*pipex)->fds[1] = open(av[4], O_WRONLY | O_CREAT, 0777);
	// check if fds worked
	// make path finder em condicoes
	(*pipex)->paths[0] = ft_strdup("/usr/bin/cat");
	(*pipex)->paths[1] = ft_strdup("/usr/bin/ls");
	temp_1 = ft_strjoin(av[2], " ");
	temp_2 = ft_strjoin(temp_1, av[1]);
	(*pipex)->comd[0] = ft_split(temp_2, ' ');
	free(temp_1);
	free(temp_2);
	// make env em condicoes
	(*pipex)->env = malloc(sizeof(char **));
	(*pipex)->env[0] = NULL;
	(*pipex)->ret = 0;
}

void	print_pipe(t_pipe *pipex)
{
	int i;

	ft_printf("pipex->temp: %d\n\n", pipex->temp);
	ft_printf("pipex->fds[0]: %d\n", pipex->fds[0]);
	ft_printf("pipex->fds[1]: %d\n\n", pipex->fds[1]);
	ft_printf("pipex->paths[0]: %s\n", pipex->paths[0]);
	ft_printf("pipex->paths[1]: %s\n\n", pipex->paths[1]);
	i = -1;
	while (pipex->comd[0][++i])
		ft_printf("pipex->comd[0][i]: %s\n", pipex->comd[0][i]);
	// ft_printf("\n");
	i = -1;
	// while (pipex->comd[1][++i])
	// 	ft_printf("pipex->comd[1][i]: %s\n", pipex->comd[1][i]);
	ft_printf("\npipex->ret: %d\n", pipex->ret);
}