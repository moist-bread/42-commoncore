/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:32:15 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// LIBS
# include "pipex.h"

// STRUCTS
typedef struct s_pipe_data
{
	int		count;
	int		**fd;
	char	***cmd;
	char	**paths;
	char	**envp;
	int		*pid;
}			t_pipe_data;

// TBD

// MAIN

// MULTI PIPE PARSING
void		pipex_struct_init(t_pipe_data **pipex, int ac, char **av,
				char **env);
void		pipex_struct_set(t_pipe_data **pipex, int ac, char **env);
// to do - struct set part 2
void		pipex_assign_paths(t_pipe_data *pipex);
char		*join_test_paths(t_pipe_data *pipex, int j, int i);

// HERE DOC HANDLER
void		here_doc_ft(void);

// EXIT HANDLER
void		pipex_free_exit(t_pipe_data *pipex, int type, int status);

// PROCESSES
void		create_pipe(t_pipe_data *pipex, int pipe_fd[2]);
void		create_child_pro(t_pipe_data *pipex, int i);

// AUX
void		**matrix_allocer(long row_size, long col_size, size_t rows,
				size_t columns);
void		print_pipe_struct(t_pipe_data *pipex);

#endif