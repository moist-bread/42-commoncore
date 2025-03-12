/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:14:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/12 17:15:44 by rduro-pe         ###   ########.fr       */
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
	(*pipex)->fd[0][1] = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT,
			0777);
	if ((*pipex)->fd[0][1] == -1)
		exit(1); // new clean pipe here
	i = -1;
	while (++i < (*pipex)->count)
		(*pipex)->cmd[i] = command_separator(av[i + 2]);
	i = -1;
	while (++i < (*pipex)->count)
		if (!*((*pipex)->cmd[i]))
			exit(1); // new clean pipe here
	pipex_assign_paths(*pipex);
	ft_printf(BLU "-- pipex struct init [ending]\n\n" DEF);
}

void	pipex_struct_set(t_pipe_data **pipex, int ac, char **env)
{
	int	i;

	ft_printf("- pipex struct set\n");

	*pipex = malloc(sizeof(t_pipe_data));
	if (!pipex)
		exit(1); // new clean pipe here
	
	(*pipex)->count = ac - 3;

	(*pipex)->fd = (int **)matrix_allocer(sizeof(int *), sizeof(int), (*pipex)->count, 2);
	if (!(*pipex)->fd)
		exit(1); // new clean pipe here

	(*pipex)->cmd = malloc(sizeof(char **) * (*pipex)->count);
	if (!(*pipex)->cmd)
		exit(1); // new clean pipe here
	
	(*pipex)->paths = (char **)ft_calloc((*pipex)->count, sizeof(char *));
	if (!(*pipex)->paths)
		exit(1); // new clean pipe here
	
	i = -1;
	(*pipex)->envp = NULL;
	while (env[++i] && !(*pipex)->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			(*pipex)->envp = ft_split(env[i] + 5, ':');
	if (!(*pipex)->envp)
		exit(1); // new clean pipe here
	
	(*pipex)->pid = (int *)ft_calloc((*pipex)->count, sizeof(int));
	if (!(*pipex)->pid)
		exit(1); // new clean pipe here
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
		exit(1); // new clean pipe here
	return (path);
}
