/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/10 18:40:40 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// LIBS
# include "pipex.h"

// STRUCTS
typedef struct s_fd_pair
{
	int			read;
	int			write;
}				t_fd_pair;

typedef struct s_pipe_data
{
	int			count;
	t_fd_pair	*fd;
	char		***cmd;
	char		**paths;
	char		**envp;
	int			*pid;
}				t_pipe_data;

// TBD
void			here_doc_ft(void);
void			pipex_struct_init(t_pipe_data **pipex, int ac, char **av,
					char **env);
void			pipex_struct_set(t_pipe_data **pipex, int ac, char **env);
void			pipex_assign_paths(t_pipe_data *pipex);
char			*join_test_paths(t_pipe_data *pipex, int j, int i);
void			print_pipe_struct(t_pipe_data *pipex);
void			pipex_free_exit(t_pipe_data *pipex, int type, int status);

// MAIN

#endif