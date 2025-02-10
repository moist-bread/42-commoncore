/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 22:16:38 by rduro-pe         ###   ########.fr       */
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