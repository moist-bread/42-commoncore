/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:33:30 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:34:06 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	**matrix_allocer(long row_size, long col_size, size_t rows, size_t columns)
{
	void **matrix;
	size_t i;

	if (!row_size || !col_size || !rows || !columns || rows > SIZE_MAX / row_size)
		return (NULL);
	matrix = malloc(row_size * rows);
	if (!matrix)
		return(NULL);
	i = -1;
	while (++i < rows)
	{
		matrix[i] = ft_calloc(columns, col_size);
		if (!matrix[i])
			return(free_matrix(matrix, i), NULL);
	}
	return(matrix);
}

void	print_pipe_struct(t_pipe_data *pipex)
{
	int	i;
	int	j;

	ft_printf(CYN "__ [printing] __\n\n" DEF);
	ft_printf(" ->count: %d\n", pipex->count);
	ft_printf(" ->fd[0][0]: %d\n", pipex->fd[0][0]);
	ft_printf(" ->fd[0][1] = %d\n\n", pipex->fd[0][1]);
	j = -1;
	while (++j < pipex->count)
	{
		i = -1;
		while (pipex->cmd[j][++i])
			ft_printf("pipex->cmd[%d][%d]: %s\n", j, i, pipex->cmd[j][i]);
		ft_printf("\n");
	}
	ft_printf("\n");
	i = -1;
	while (++i < pipex->count)
		ft_printf("pipex->paths[%d]: %s\n", i, pipex->paths[i]);
	ft_printf("\n");
	if (pipex->envp[0])
		ft_printf("pipex->envp? : yes\n");
	ft_printf(CYN "\n__   [over]  __\n\n" DEF);
}
