/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 16:30:18 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// LIBS
# include "pipex.h"

// STRUCTS

/// @param count amount of cmds
/// @param fd stores infile fd, pipe fds, outfile fd
/// @param cmd commands and their parameters
/// @param paths paths to said cmds 
/// @param pid stores child process ids
/// @param env environment
typedef struct s_pipe_data
{
	int		count;
	int		**fd;
	char	***cmd;
	char	**paths;
	int		*pid;
	char	**env;
}			t_pipe_data;

// MULTI PIPE PARSING

void		pipex_struct_init(t_pipe_data **pipex, int ac, char **av,
				char **env);
void		pipex_struct_set(t_pipe_data **pipex, int ac, char **env);
void		pipex_assign_paths(t_pipe_data *pipex);
void		path_tester(t_pipe_data *pipex, char **envp);
char		*join_test_paths(t_pipe_data *pipex, char **envp, int j, int i);

// EXIT HANDLER

void		pipex_free_exit(t_pipe_data *pipex, int type, int status);
void		pipex_data_free(t_pipe_data *pipex, int type);
void		pipex_cmd_free(t_pipe_data *pipex);
void		close_all_fds(t_pipe_data *pipex);

// PROCESSES

void		here_doc_handler(t_pipe_data *pipex, char *limiter);
void		create_pipe(t_pipe_data *pipex, int i);
void		create_child_pro(t_pipe_data *pipex, int i);
void		process_setup(t_pipe_data *pipex, int i);
void		multi_process_waiting(t_pipe_data *pipex, int *status);

// AUX

void		**matrix_allocer(long row_size, long col_size, size_t rows,
				size_t columns);
void		print_pipe_struct(t_pipe_data *pipex);

#endif