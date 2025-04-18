/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 16:42:58 by rduro-pe         ###   ########.fr       */
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
# define BLU "\e[0;34m"
# define CYN "\e[0;36m"
# define DEF "\e[0m"

// bg colors
# define YELB "\e[43m"

// STRUCTS
typedef struct s_pipe
{
	int		pid[2];
	int		fd[2][2];
	char	**comd[2];
	char	**envp;
	char	*paths[2];
	char	**env;
}			t_pipe;

typedef struct s_crossfd
{
	int		in_read;
	int		in_write;
	int		out_read;
	int		out_write;
}			t_crossfd;

// UTILS

void		pipex_init(t_pipe **pipex, char **av, char **env);
void		find_paths(t_pipe *pipex, int n);
char		*make_path(t_pipe *pipex, int j, int i);
void		child_process(t_crossfd fd, t_pipe *pipex, int i);
void		process_waiting(t_pipe *pipex, int *status);

// DESTROYERS

void		clean_pipes_exit(t_pipe *pipex, int type, int status);
void		free_pipe(t_pipe *pipex, int status, int i);
void		free_matrix(void **matrix, int max);
void		print_pipe(t_pipe *pipex);

// COMMAND PARSING

char		**command_separator(char const *s);

#endif