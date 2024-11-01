/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:48:25 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/01 16:20:29 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content);

int main (void)
{
	char *con = "conteudo interessante";
	ft_lstnew((void *)con);
	return(0);
}

*/

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return(NULL);
	new->content = content;
	new->next = NULL;
	return(new);
}