/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:38 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/14 19:40:39 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	here_doc_ft(t_pipe_data *pipex)
{
	char *line;

	ft_printf("-- here doc [beggining]\n");
	if (pipex->fd[0][0] == -1)
	pipex_free_exit(pipex, 12, 12);
	line = NULL;
	while (1)
	{
		line = get_next_line(1);
		write(pipex->fd[0][0], &line, ft_strlen(line)); // fix me pls
		if (!ft_strncmp(line, *pipex->cmd[0], ft_strlen(*pipex->cmd[0])))
			break;
		free(line);	
	}
	free(line);
	ft_printf("-- here doc [ending]\n\n");
}
