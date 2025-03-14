/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:25:25 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 16:44:49 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

// bonus exit meanings
// 1:  not enough input
// 2:  struct didnt malloc
// 3:  fd matrix didnt alloc
// 4:  cmd ** didnt malloc
// 5:  paths didnt malloc
// 6:  pid didnt malloc
// 7:  outfile didnt open
// 8:  command didnt malloc
// 9:  no env paths (or failed to malloc)
// 10: test paths didnt malloc
// 11: path didnt malloc
// 12: here doc infile didnt open
// 13: pipe failure
// 14: fork failure
// 15: command failure
// 16: no infile fd
// 17: no problems exit

/// @brief frees alloced memory and exits program
/// (displays error message if needed)
/// @param pipex struct with all needed fds, cmds, paths and ids
/// @param type used to determine what needs to be freed
/// @param status program exit status
void	pipex_free_exit(t_pipe_data *pipex, int type, int status)
{
	if (type == 1 || type == 8)
		ft_printf(YEL "not enough arguments" DEF ": accepted format is "
			YELB" infile \"cmd1\" \"cmd2\" ... outfile " DEF "\n");
	if (type == 8)
		ft_printf("OR\n");
	if (type >= 2 && type <= 11 && type != 7 && type != 9)
		ft_printf(YEL "malloc failure during parsing\n" DEF);
	else if (type == 7)
		perror(YEL "outfile open failure" DEF);
	else if (type == 9)
		perror(YEL "no env paths present or malloc failure of said paths" DEF);
	else if (type == 12)
		perror(YEL "here_doc infile open failure" DEF);
	else if (type == 13)
		perror(YEL "pipe unsuccessfull" DEF);
	else if (type == 14)
		perror(YEL "fork unsuccessfull" DEF);
	else if (type == 15)
		perror(YEL "command not found" DEF);
	else if (type == 16)
		perror(YEL "no infile fd" DEF);
	if (type > 2)
		pipex_data_free(pipex, type);
	exit(status);
}

void	pipex_data_free(t_pipe_data *pipex, int type)
{
	int	i;

	i = -1;
	while (type > 9 && ++i < pipex->count)
		if (pipex->paths[i])
			free(pipex->paths[i]);
	if (type > 6)
	{
		pipex_cmd_free(pipex);
		close_all_fds(pipex);
		free(pipex->pid);
	}
	i = -1;
	if (type > 5)
		free(pipex->paths);
	if (type > 4)
		free(pipex->cmd);
	if (type > 3)
		free_matrix((void **)pipex->fd, pipex->count - 1);
	free(pipex);
}

void	pipex_cmd_free(t_pipe_data *pipex)
{
	int	i;
	int	j;

	j = -1;
	while (++j < pipex->count)
	{
		i = -1;
		while (pipex->cmd[j][++i])
			;
		if (pipex->cmd[j])
			free_matrix((void **)pipex->cmd[j], i);
	}
}

void	close_all_fds(t_pipe_data *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->count)
	{
		if (pipex->fd[i][0] > 2)
			close(pipex->fd[i][0]);
		if (pipex->fd[i][1] > 2)
			close(pipex->fd[i][1]);
	}
}
