/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:52:42 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/01 18:00:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new);

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return (NULL);
	while((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = new;
}