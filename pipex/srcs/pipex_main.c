/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/04 13:54:11 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	int		pipe_fds[2];
	int		status;

	if (argc != 5 || !*argv[2] || !*argv[3])
		clean_pipes_exit(NULL, 1, 1);
	pipex_init(&pipex, argv, envp);
	if (pipe(pipe_fds) == -1)
		clean_pipes_exit(pipex, 7, 7);
	pipex->fd[0][1] = pipe_fds[1];
	pipex->fd[1][0] = pipe_fds[0];
	child_process((t_crossfd){pipex->fd[0][0], pipex->fd[0][1], pipex->fd[1][0],
		pipex->fd[1][1]}, pipex, 0);
	close(pipex->fd[0][1]);
	child_process((t_crossfd){pipex->fd[1][0], pipex->fd[1][1], pipex->fd[0][0],
		pipex->fd[0][1]}, pipex, 1);
	close(pipex->fd[1][0]);
	process_waiting(pipex, &status);
	close(pipex->fd[1][1]);
	if (pipex->fd[0][0] != -1)
		close(pipex->fd[0][0]);
	clean_pipes_exit(pipex, 10, status);
}
