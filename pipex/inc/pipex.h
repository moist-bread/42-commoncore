/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/10 22:10:35 by rduro-pe         ###   ########.fr       */
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
# include <unistd.h>

// DEFINES
// colors
# define YEL "\e[0;33m"
# define DEF "\e[0m"

// STRUCTS
typedef struct s_pipe
{
	int		temp;
	int		fds[2];
	char	*paths[2];
	char	**command[2];
	char	**env;
	int		ret;
}			t_pipe;

// TBD

// MAIN

#endif