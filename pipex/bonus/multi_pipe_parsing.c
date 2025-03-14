/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/14 17:30:04 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	pipex_struct_init(t_pipe_data **pipex, int ac, char **av, char **env)
{
	int	i;

	ft_printf(BLU "-- pipex struct init [beggining]\n" DEF);
	pipex_struct_set(pipex, ac, env);
	if (ft_strncmp(av[1], "here_doc", 9))
		(*pipex)->fd[0][0] = open(av[1], O_RDONLY);
	else
		(*pipex)->fd[0][0] = open(av[1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	(*pipex)->fd[(*pipex)->count - 1][1] = open(av[ac - 1],
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*pipex)->fd[(*pipex)->count - 1][1] == -1)
		pipex_free_exit(*pipex, 8, 8);
	i = -1;
	while (++i < (*pipex)->count)
		(*pipex)->cmd[i] = command_separator(av[i + 2]);
	i = -1;
	while (++i < (*pipex)->count)
		if (!*((*pipex)->cmd[i]))
			pipex_free_exit(*pipex, 9, 9);
	pipex_assign_paths(*pipex);
	(*pipex)->env = env;
	ft_printf(BLU "-- pipex struct init [ending]\n\n" DEF);
}

void	pipex_struct_set(t_pipe_data **pipex, int ac, char **env)
{
	ft_printf("- pipex struct set\n");
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
	env_path_finder(pipex, env);
	(*pipex)->pid = (int *)ft_calloc((*pipex)->count, sizeof(int));
	if (!(*pipex)->pid)
		pipex_free_exit((*pipex), 7, 7);
}

void	env_path_finder(t_pipe_data **pipex, char **env)
{
	int	i;

	i = -1;
	(*pipex)->envp = NULL;
	while (env[++i] && !(*pipex)->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			(*pipex)->envp = ft_split(env[i] + 5, ':');
	if (!(*pipex)->envp)
		pipex_free_exit((*pipex), 6, 6);
}

void	pipex_assign_paths(t_pipe_data *pipex)
{
	int		i;
	int		j;
	int		result;
	char	*path;

	ft_printf("- pipex assign paths\n");
	j = -1;
	while (++j < pipex->count)
	{
		i = -1;
		result = 1;
		while (pipex->envp[++i] && result)
		{
			path = join_test_paths(pipex, j, i);
			result = access(path, F_OK);
			if (!result)
				pipex->paths[j] = ft_strdup(path);
			else if (!pipex->envp[i + 1])
				pipex->paths[j] = ft_strdup(pipex->cmd[j][0]);
			free(path);
		}
		if (!pipex->paths[j])
			pipex_free_exit(pipex, 11, 11);
	}
}

char	*join_test_paths(t_pipe_data *pipex, int j, int i)
{
	char	*temp;
	char	*path;

	ft_printf("- join test paths\n");
	temp = ft_strjoin(pipex->envp[i], "/");
	path = ft_strjoin(temp, pipex->cmd[j][0]);
	if (temp)
		free(temp);
	if (!path)
		pipex_free_exit(pipex, 10, 10);
	return (path);
}
