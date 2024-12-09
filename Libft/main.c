/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:35:34 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/09 16:59:57 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str);

/* int main(int argc, char *argv[])
{
	char	**splitted;
	int		i;

	if (argc > 2 || argc == 1)
		return(1);
	splitted = ft_split(argv[1], ' ');
	i = 0;
	while (splitted[i] != NULL)
		ft_putendl_fd(splitted[i++], 2);
	ft_free(splitted);
} */
void	print(void *content)
{
	ft_putendl_fd(content, 1);
}

void	waaa(void *nome)
{
	(void)nome;
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("goncalo")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("raquel")));
	ft_lstiter(list, print);
	ft_lstclear(&list, free);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++]);
	}
	free(str);
}
