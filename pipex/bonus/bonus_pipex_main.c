/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:55:28 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/10 18:44:19 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*pipex;
	int			pipe_fd[2];
	int			status;
	int			i;

	(void)envp;
	(void)pipex;
	(void)pipe_fd;
	(void)status;
	ft_printf(YEL "PIPEX BONUS MAIN [BEGGINING]\n\n" DEF);
	if (argc < 5 || !*argv[2] || !*argv[3])
		exit(1); // new clean pipe here
	pipex_struct_init(&pipex, argc, argv, envp);
	print_pipe_struct(pipex);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_ft();
	i = -1;
	while (++i < pipex->count)
	{
		create_pipe();
		if (pipe(pipe_fd) == -1)
			exit(1); // new clean pipe here
	}
}

void	create_pipe(t_pipe_data **pipex, int pipe_fd[2])
{
	(void)pipex;
}

void	create_child_pro(void)
{
}

void	pipex_struct_init(t_pipe_data **pipex, int ac, char **av, char **env)
{
	int	i;

	ft_printf("-- pipex struct init [beggining]\n");
	pipex_struct_set(pipex, ac, env);
	if (ft_strncmp(av[1], "here_doc", 9))
		(*pipex)->fd[0].read = open(av[1], O_RDONLY);
	else
		(*pipex)->fd[0].read = open(av[1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	(*pipex)->fd[0].write = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT,
			0777);
	if ((*pipex)->fd[0].write == -1)
		exit(1); // new clean pipe here
	i = -1;
	while (++i < (*pipex)->count)
		(*pipex)->cmd[i] = command_separator(av[i + 2]);
	i = -1;
	while (++i < (*pipex)->count)
		if (!*((*pipex)->cmd[i]))
			exit(1); // new clean pipe here
	pipex_assign_paths(*pipex);
	ft_printf("-- pipex struct init [ending]\n\n");
}
void	pipex_struct_set(t_pipe_data **pipex, int ac, char **env)
{
	int	i;

	ft_printf("- pipex struct set\n");
	*pipex = malloc(sizeof(t_pipe_data));
	if (!pipex)
		exit(1); // new clean pipe here
	(*pipex)->count = ac - 3;
	(*pipex)->fd = malloc(sizeof(t_fd_pair) * (*pipex)->count);
	ft_bzero((*pipex)->fd, (*pipex)->count);
	(*pipex)->cmd = malloc(sizeof(char **) * (*pipex)->count);
	if (!(*pipex)->cmd)
		exit(1); // new clean pipe here
	(*pipex)->paths = malloc(sizeof(char *) * (*pipex)->count);
	if (!(*pipex)->paths)
		exit(1); // new clean pipe here
	ft_bzero((*pipex)->paths, (*pipex)->count);
	i = -1;
	(*pipex)->envp = NULL;
	while (env[++i] && !(*pipex)->envp)
		if (!ft_strncmp(env[i], "PATH=", 5))
			(*pipex)->envp = ft_split(env[i] + 5, ':');
	if (!(*pipex)->envp)
		exit(1); // new clean pipe here
	(*pipex)->pid = malloc(sizeof(int) * (*pipex)->count);
	if (!(*pipex)->pid)
		exit(1); // new clean pipe here
	ft_bzero((*pipex)->pid, (*pipex)->count - 1);
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

void	here_doc_ft(void)
{
	ft_printf("-- here doc [beggining]\n");
	ft_printf("-- here doc [ending]\n\n");
}

void	print_pipe_struct(t_pipe_data *pipex)
{
	int	i;
	int	j;

	ft_printf("__ [printing] __\n\n");
	ft_printf(" ->count: %d\n", pipex->count);
	ft_printf(" ->fd[0].read: %d\n", pipex->fd[0].read);
	ft_printf(" ->fd[0].write = %d\n\n", pipex->fd[0].write);
	j = -1;
	while (++j < pipex->count)
	{
		i = -1;
		while (pipex->cmd[j][++i])
			ft_printf("pipex->cmd[%d][%d]: %s\n", j, i, pipex->cmd[j][i]);
		ft_printf("\n");
	}
	ft_printf("\n");
	i = -1;
	while (++i < pipex->count)
		ft_printf("pipex->paths[%d]: %s\n", i, pipex->paths[i]);
	ft_printf("\n");
	i = -1;
	while (pipex->envp[++i])
		ft_printf("pipex->envp[%d]: %s\n", i, pipex->envp[i]);
	ft_printf("\n");
	ft_printf("\n__   [over]  __\n\n");
}

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