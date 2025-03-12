/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:35:41 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 16:22:00 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// exit meanings
// 1: not enough input
// 2: pipex didnt malloc
// 3: files doent exist or didnt create
// 4: failed to malloc commands
// 5: failed to find or malloc env paths
// 6: failed a path malloc
// 7: pipe fail
// 8: fork fail
// 9: command fail
// 10: success

void	clean_pipes_exit(t_pipe *pipex, int type, int status)
{
	if (type == 1)
		ft_printf(YEL "incorrect format" DEF
			": accepted format is \" infile \"cmd1\" \"cmd2\" outfile \"\n");
	else if (type == 2)
		ft_printf(YEL "malloc failure" DEF ": pipex struct\n");
	else if (type == 3)
		perror(YEL "infile or outfile open failure" DEF);
	else if (type == 4)
		ft_printf(YEL "malloc failure" DEF ": cmd1 or cmd2\n");
	else if (type == 5 || type == 6)
		ft_printf(YEL "path failure" DEF ": couldn't find or malloc paths\n");
	else if (type == 7)
		perror(YEL "pipe unsuccessfull" DEF);
	else if (type == 8)
		perror(YEL "fork unsuccessfull" DEF);
	else if (type == 9)
		perror(YEL "command not found" DEF);
	if (type > 2)
		free_pipe(pipex, type, -1);
	exit(status);
}

void	free_pipe(t_pipe *pipex, int status, int i)
{
	int	j;

	while (status >= 6 && pipex->envp[++i])
		;
	if (status >= 6)
		free_matrix((void **)pipex->envp, i);
	if (status >= 6 && pipex->paths[0])
		free(pipex->paths[0]);
	if (status >= 6 && pipex->paths[1])
		free(pipex->paths[1]);
	j = -1;
	while (status >= 4 && ++j <= 1)
	{
		i = -1;
		while (pipex->comd[j][++i])
			;
		if (pipex->comd[j])
			free_matrix((void **)pipex->comd[j], i);
	}
	if (pipex->fd[0][0] != -1)
		close (pipex->fd[0][0]);
	if (pipex->fd[1][1] != -1)
		close (pipex->fd[1][1]);
	free(pipex);
}

void	free_matrix(void **matrix, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		free(matrix[i++]);
	free(matrix);
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
		ft_printf("pipex->comd[0][%d]: %s\n", i, pipex->comd[0][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->comd[1][++i])
		ft_printf("pipex->comd[1][%d]: %s\n", i, pipex->comd[1][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->envp[++i])
		ft_printf("pipex->envp[%d]: %s\n", i, pipex->envp[i]);
	ft_printf("\n");
	ft_printf("pipex->paths[0]: %s\n", pipex->paths[0]);
	ft_printf("pipex->paths[1]: %s\n\n", pipex->paths[1]);
}
