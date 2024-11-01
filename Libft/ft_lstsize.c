/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:36:35 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/01 17:44:06 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst);
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);

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
	printf("%d(list size)\n", ft_lstsize(first));
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

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	while(lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (++size);
}