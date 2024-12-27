/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:58 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:46:08 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa_do(t_stacks *stk, int flag)
{
	int	temp;

	if (flag)
		ft_printf("sa\n");
	if (stk->atop_id > 0)
	{
		temp = stk->a[stk->atop_id];
		stk->a[stk->atop_id] = stk->a[stk->atop_id - 1];
		stk->a[stk->atop_id - 1] = temp;
	}
}

void	sb_do(t_stacks *stk, int flag)
{
	int	temp;

	if (flag)
		ft_printf("sb\n");
	if (stk->btop_id > 0)
	{
		temp = stk->b[stk->btop_id];
		stk->b[stk->btop_id] = stk->b[stk->btop_id - 1];
		stk->b[stk->btop_id - 1] = temp;
	}
}

void	ss_do(t_stacks *stk)
{
	ft_printf("ss\n");
	sa_do(stk, 0);
	sb_do(stk, 0);
}
