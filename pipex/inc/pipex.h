/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/13 19:07:28 by rduro-pe         ###   ########.fr       */
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
	int		temp;
	int		io[2];
	int		fds[2];
	char	*paths[2];
	char	*path[2];
	char	**envp;
	char	**comd[2];
	char	**env;
	int		ret;
}			t_pipe;

// TBD
void		pipex_init(t_pipe **pipex, char **av, char **env);
void		print_pipe(t_pipe *pipex);

// MAIN

#endif