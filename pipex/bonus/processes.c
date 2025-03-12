/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:30:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:32:33 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	create_pipe(t_pipe_data *pipex, int pipe_fd[2])
{
	ft_printf(BLU "-- create pipe [beggining]\n" DEF);
	if (pipe(pipe_fd) == -1)
	exit(1); // new clean pipe here
	(void)pipex;
	ft_printf(BLU "-- create pipe [ending]\n\n" DEF);
}

void	create_child_pro(t_pipe_data *pipex, int i)
{
	ft_printf(BLU "-- create child pro [beggining]\n" DEF);
	(void)pipex;
	(void)i;
	ft_printf(BLU "-- create child pro [ending]\n\n" DEF);
}
