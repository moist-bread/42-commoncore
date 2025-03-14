/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:55:28 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/14 15:17:53 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*pipex;
	int			status;
	int			i;

	ft_printf(YEL "PIPEX BONUS MAIN [BEGGINING]\n\n" DEF);
	if (argc < 5 || !*argv[2] || !*argv[3])
		pipex_free_exit(pipex, 1, 1);
	pipex_struct_init(&pipex, argc, argv, envp);
	print_pipe_struct(pipex);
	i = -1;
	if (!ft_strncmp(argv[1], "here_doc", 9) && !++i)
		here_doc_ft(pipex); // MAKE THE FUNCTION
	while (++i < pipex->count)
	{
		if (i + 1 != pipex->count)
			create_pipe(pipex, i);
		print_pipe_struct(pipex);
		create_child_pro(pipex, i);
		if (i + 1 == pipex->count)
			close (pipex->fd[i][0]);
		else
			close (pipex->fd[i][1]);
	}
	// fd 7 open everywhere????
	multi_process_waiting(pipex, &status);
	pipex_free_exit(pipex, 17, status);
}
