/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:53:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/19 16:10:41 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	clean_pipes_exit(t_pipe *pipex, int status)
{
	int	i;

	i = -1;
	if (status == 1)
		ft_printf(YEL "not enough arguments" DEF 
		": accepted format is \" infile \"cmd1\" \"cmd2\" outfile \"\n");
	else if (status == 2)
		ft_printf(YEL "malloc failure" DEF ": pipex struct\n");
	else if (status == 3)
		ft_printf(YEL "open failure" DEF ": infile or outfile didn't open\n");
	else if (status == 4)
		ft_printf(YEL "malloc failure" DEF ": cmd1 or cmd2\n");
	else if (status == 5 || status == 6)
		ft_printf(YEL "path failure" DEF ": couldn't find or malloc paths\n");
	else if (status == 7)
		perror(YEL "pipe unsuccessfull" DEF);
	else if (status == 8)
		perror(YEL "fork unsuccessfull" DEF);
	else if (status == 9)
		perror(YEL "command didn't execute" DEF);
	free_pipe(pipex, status);
	exit(status);
}

void	free_pipe(t_pipe *pipex, int status)
{
	int	i;
	int	j;

	i = -1;
	while (status >= 6 && pipex->envp[++i])
		;
	if (status >= 6)
		free_matrix(pipex->envp, i);
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
			free_matrix(pipex->comd[j], i);
	}
	if (status >= 3)
		free(pipex);
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
