/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:11:31 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/01 17:34:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new);
t_list *ft_lstnew(void *content);

/*

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

int main (void)
{
	char *t3 = "last";
	char *t2 = "secon";
	char *t1 = "first";
	t_list *last = ft_lstnew((void *)t3);
	t_list *secon = ft_lstnew((void *)t2);
	t_list *first = ft_lstnew((void *)t1);
	t_list **list = &last;
	ft_lstadd_front(list, secon);
	ft_lstadd_front(list, first);
	int i = 1;
	while((*list)->next != NULL)
	{
		printf("%s(content %d)\n", (char *)(*list)->content, i);
		i++;
		*list = (*list)->next;
	}
	printf("%s(content %d)\n", (char *)(*list)->content, i);
	return(0);
}

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
*/

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
