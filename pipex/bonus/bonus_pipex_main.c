/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:55:28 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:37:44 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*pipex;
	int			status;
	int			i;

	(void)status;
	ft_printf(YEL "PIPEX BONUS MAIN [BEGGINING]\n\n" DEF);
	if (argc < 5 || !*argv[2] || !*argv[3])
		exit(1); // new clean pipe here
	pipex_struct_init(&pipex, argc, argv, envp);
	print_pipe_struct(pipex);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_ft();
	i = -1;
	while (++i < pipex->count)
	{
		if (i + 1 != pipex->count)
			create_pipe(pipex, pipex->fd[i + 1]);
		create_child_pro(pipex, i);
	}
}
