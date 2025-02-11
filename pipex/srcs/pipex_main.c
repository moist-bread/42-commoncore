/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/11 16:10:12 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	t_pipe	pipex;
	int		result;
	char	*pathname;
	char	*temp;
	char	**command;
	char	*env[] = {NULL};
	int		i;

	if (argc != 5)
		return (1);
	result = access(argv[1], F_OK);
	ft_printf("%d (file 1)\n", result);
	if (result == -1)
		return (perror(YEL "no file found" DEF), 2);
	result = access(argv[4], F_OK);
	ft_printf("%d (file 2)\n\n", result);
	pipex_init(&pipex, argv);
	pathname = ft_strdup("/usr/bin/ls");
	temp = ft_strjoin(argv[2], " ");
	temp = ft_strjoin(temp, argv[1]);
	command = ft_split(temp, ' ');
	i = -1;
	while (command[++i])
		ft_printf("command[%d]%s\n", i, command[i]);
	i = -1;
	while (env[++i])
		ft_printf("env[%d]%s\n", i, env[i]);
	ft_printf("\n_____________\n\n");
	if (execve(pathname, command, env) == -1)
		return (perror(YEL "command didn't execute" DEF), 4);
}

// exit meanings
// 1: not enough input
// 2: file 1 doesnt exists
// 3: malloc issues
// 4: command didnt execute

void	pipex_init(t_pipe *pipex, char **av)
{
	pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		return ;
	pipex->temp = 0;
	pipex->fds[0] = open(av[1], O_RDONLY);
	pipex->fds[1] = open(av[4], O_RDONLY);
	pipex->paths[0] = ft_strdup("/usr/bin/ls");
	pipex->paths[1] = ft_strdup("/usr/bin/cat");
}

void	print_pipe(t_pipe pipex)
{
	int i;

	ft_printf("pipex.temp: %d", pipex.temp);
	ft_printf("pipex.fds[0]: %d", pipex.fds[0]);
	ft_printf("pipex.fds[1]: %d", pipex.fds[1]);
	ft_printf("pipex.paths[0]: %s", pipex.paths[0]);
	ft_printf("pipex.paths[1]: %s", pipex.paths[1]);
	i = -1;
	while (pipex.comd[0][++i])
		ft_printf("pipex.comd[0][i]: %s", pipex.comd[0][i]);
	i = -1;
	while (pipex.comd[1][++i])
		ft_printf("pipex.comd[1][i]: %s", pipex.comd[1][i]);
	ft_printf("pipex.ret: %d", pipex.ret);
	
}