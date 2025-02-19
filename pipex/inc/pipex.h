/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/19 18:32:28 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// LIBS
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

// DEFINES
// colors
# define YEL "\e[0;33m"
# define DEF "\e[0m"

// STRUCTS
typedef struct s_pipe
{
	int		fd[2][2];
	char	**comd[2];
	char	**envp;
	char	*paths[2];
	char	**env;
}			t_pipe;

// TBD
void		pipex_init(t_pipe **pipex, char **av, char **env);
void		print_pipe(t_pipe *pipex);
void		find_paths(t_pipe *pipex, int n);
void		clean_pipes_exit(t_pipe *pipex, int status);
void		free_pipe(t_pipe *pipex, int status);
void		free_matrix(char **matrix, int max);
void		child_pro(t_pipe *pipex, int in_fd[2], int out_fd[2]);

// MAIN

#endif