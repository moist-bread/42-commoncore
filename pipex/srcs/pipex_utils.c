/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:53:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/18 20:03:25 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	clean_pipes_exit(t_pipe *pipex, int status)
{
	int	i;

	i = -1;
	// if (status == 10)
	// {
	// }
	if (status > 1)
		free_pipe(pipex, status);
	if (status == 1)
		ft_printf(YEL "not enough arguments:" DEF
		" accepted format is \" infile \"cmd1\" \"cmd2\" outfile \"\n");
	(void)pipex;
	exit(status); // make it good
}

void	free_pipe(t_pipe *pipex, int status)
{
	int	i;
	int	j;

	i = -1;
	while (pipex->envp[++i])
		;
	free_matrix(pipex->envp, i);
	free(pipex->paths[0]);
	free(pipex->paths[1]);
	j = -1;
	while (++j <= 1)
	{
		i = -1;
		while (pipex->comd[j][++i])
			;
		free_matrix(pipex->comd[j], i);
	}
	free(pipex);
	(void)status;
}

void	free_matrix(char **matrix, int max)
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
		ft_printf("pipex->comd[0][i]: %s\n", pipex->comd[0][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->comd[1][++i])
		ft_printf("pipex->comd[1][i]: %s\n", pipex->comd[1][i]);
	ft_printf("\n");
	i = -1;
	while (pipex->envp[++i])
		ft_printf("pipex->envp[%d]: %s\n", i, pipex->envp[i]);
	ft_printf("\n");
	ft_printf("pipex->paths[0]: %s\n", pipex->paths[0]);
	ft_printf("pipex->paths[1]: %s\n\n", pipex->paths[1]);
}
