/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:47:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 11:24:48 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
