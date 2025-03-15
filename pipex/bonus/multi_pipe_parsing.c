/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 16:50:08 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/// @brief allocs and fills out PIPEX according to AC, AV and ENV
/// @param pipex pointer to struct to fill out with
/// all needed fds, cmds and paths
void	pipex_struct_init(t_pipe_data **pipex, int ac, char **av, char **env)
{
	int	i;

	if (ft_strncmp(av[1], "here_doc", 9))
	{
		pipex_struct_set(pipex, ac, env);
		(*pipex)->fd[0][0] = open(av[1], O_RDONLY);
	}
	else
	{
		pipex_struct_set(pipex, --ac, env);
		(*pipex)->fd[0][0] = open(*(++av), O_WRONLY | O_TRUNC | O_CREAT, 0777);
	}
	(*pipex)->fd[(*pipex)->count - 1][1] = open(av[ac - 1],
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*pipex)->fd[(*pipex)->count - 1][1] == -1)
		pipex_free_exit(*pipex, 7, 7);
	i = -1;
	while (++i < (*pipex)->count)
		(*pipex)->cmd[i] = command_separator(av[i + 2]);
	i = -1;
	while (++i < (*pipex)->count)
		if (!*((*pipex)->cmd[i]))
			pipex_free_exit(*pipex, 8, 8);
	pipex_assign_paths(*pipex);
}

void	pipex_struct_set(t_pipe_data **pipex, int ac, char **env)
{
	if (ac < 5)
		pipex_free_exit(*pipex, 1, 1);
	*pipex = malloc(sizeof(t_pipe_data));
	if (!pipex)
		pipex_free_exit((*pipex), 2, 2);
	(*pipex)->count = ac - 3;
	(*pipex)->fd = (int **)matrix_allocer(sizeof(int *), sizeof(int),
			(*pipex)->count, 2);
	if (!(*pipex)->fd)
		pipex_free_exit((*pipex), 3, 3);
	(*pipex)->cmd = malloc(sizeof(char **) * (*pipex)->count);
	if (!(*pipex)->cmd)
		pipex_free_exit((*pipex), 4, 4);
	(*pipex)->paths = (char **)ft_calloc((*pipex)->count, sizeof(char *));
	if (!(*pipex)->paths)
		pipex_free_exit((*pipex), 5, 5);
	(*pipex)->env = env;
	(*pipex)->pid = (int *)ft_calloc((*pipex)->count, sizeof(int));
	if (!(*pipex)->pid)
		pipex_free_exit((*pipex), 6, 6);
}

void	pipex_assign_paths(t_pipe_data *pipex)
{
	int		i;
	char	**envp;

	i = -1;
	envp = NULL;
	while (pipex->env && pipex->env[++i] && !envp)
		if (!ft_strncmp(pipex->env[i], "PATH=", 5))
			envp = ft_split(pipex->env[i] + 5, ':');
	if (!envp)
		pipex_free_exit(pipex, 9, 9);
	path_tester(pipex, envp);
	i = -1;
	while (envp[++i])
		;
	free_matrix((void **)envp, i);
}

void	path_tester(t_pipe_data *pipex, char **envp)
{
	int		i;
	int		j;
	int		result;
	char	*path;

	j = -1;
	while (++j < pipex->count)
	{
		i = -1;
		result = 1;
		while (envp[++i] && result)
		{
			path = join_test_paths(pipex, envp, j, i);
			result = access(path, F_OK);
			if (!result)
				pipex->paths[j] = ft_strdup(path);
			else if (!envp[i + 1])
				pipex->paths[j] = ft_strdup(pipex->cmd[j][0]);
			free(path);
		}
		if (!pipex->paths[j])
			pipex_free_exit(pipex, 11, 11);
	}
}

char	*join_test_paths(t_pipe_data *pipex, char **envp, int j, int i)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(envp[i], "/");
	path = ft_strjoin(temp, pipex->cmd[j][0]);
	if (temp)
		free(temp);
	if (!path)
	{
		i = -1;
		while (envp[++i])
			;
		free_matrix((void **)envp, i);
		pipex_free_exit(pipex, 10, 10);
	}
	return (path);
}
