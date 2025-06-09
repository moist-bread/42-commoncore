/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/09 12:53:52 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

// LIBS
# include "philo.h"

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

#endif