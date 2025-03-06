/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:55:28 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/06 17:20:19 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	int		pipe_fds[2];
	int		status;
	int		i;

	(void)envp;
	(void)pipex;
	(void)pipe_fds;
	(void)status;
	ft_printf("BONUS TESTING TESTING\n");
	if (argc < 5 || !*argv[2] || !*argv[3])
		clean_pipes_exit(NULL, 1, 1);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_ft();
	i = 1;
	multi_pipex_init();
	/*
	fd cross
	fd[0][0] - infile
	fd[0][1] - pipe_1 write end
	fd[1][0] - pipe_1 read end
	fd[1][1] - pipe_2 write end
	next loop
	fd[0][0] - pipe_2 read end
	fd[0][1] - pipe_1 write end
	fd[1][0] - pipe_1 read end
	fd[1][1] - pipe_2 write end
	*/
	/* pipex_init(&pipex, argv, envp);
	if (pipe(pipe_fds) == -1)
		clean_pipes_exit(pipex, 7, 7);
	pipex->fd[0][1] = pipe_fds[1];
	pipex->fd[1][0] = pipe_fds[0];
	child_process((t_crossfd){pipex->fd[0][0], pipex->fd[0][1], pipex->fd[1][0],
		1}, pipex, 0);
	close(pipex->fd[0][1]);
	child_process((t_crossfd){1, pipex->fd[0][1], pipex->fd[1][0],
		pipex->fd[1][1]}, pipex, 0);
	child_process((t_crossfd){pipex->fd[1][0], pipex->fd[1][1], pipex->fd[0][0],
		pipex->fd[0][1]}, pipex, 1);
	close(pipex->fd[1][0]);
	process_waiting(pipex, &status);
	close(pipex->fd[1][1]);
	if (pipex->fd[0][0] != -1)
		close(pipex->fd[0][0]);
	clean_pipes_exit(pipex, 10, status); */
}

void	multi_pipex_init(void)
{
	ft_printf("multi pipe init\n");
}

void	here_doc_ft(void)
{
	ft_printf("here we doc\n");
}