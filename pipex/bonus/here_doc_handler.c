/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:38 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/14 13:18:05 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	here_doc_ft(t_pipe_data *pipex)
{
	ft_printf("-- here doc [beggining]\n");
	if (pipex->fd[0][0] == -1)
		pipex_free_exit(pipex, 12, 12);
	ft_printf("-- here doc [ending]\n\n");
}
