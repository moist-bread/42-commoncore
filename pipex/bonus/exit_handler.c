/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:25:25 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:25:57 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

// bonus exit meanings
// 1: not enough input
// 2: pipex didnt malloc
// 3: files doent exist or didnt create
// 4: failed to malloc commands
// 5: failed to find or malloc env paths
// 6: failed a path malloc
// 7: pipe fail
// 8: fork fail
// 9: command fail
// 10: success

void	pipex_free_exit(t_pipe_data *pipex, int type, int status)
{
	if (type == 1)
		ft_printf(YEL "incorrect format" DEF ": accepted format is \" infile \"cmd1\" \"cmd2\" outfile \"\n");
	else if (type == 2)
		ft_printf(YEL "malloc failure" DEF ": pipex struct\n");
	else if (type == 3)
		perror(YEL "infile or outfile open failure" DEF);
	else if (type == 4)
		ft_printf(YEL "malloc failure" DEF ": cmd1 or cmd2\n");
	else if (type == 5 || type == 6)
		ft_printf(YEL "path failure" DEF ": couldn't find or malloc paths\n");
	else if (type == 7)
		perror(YEL "pipe unsuccessfull" DEF);
	else if (type == 8)
		perror(YEL "fork unsuccessfull" DEF);
	else if (type == 9)
		perror(YEL "command not found" DEF);
	if (type > 2)
		// free_pipe(pipex, type, -1);
	(void)pipex;
	exit(status);
}
