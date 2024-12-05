/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:58 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/05 17:38:03 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_do(stacks *stk)
{
	int temp;
	
	if (stk->atop_id > 0)
	{
		temp = stk->a[stk->atop_id];
		stk->a[stk->atop_id] = stk->a[stk->atop_id - 1];
		stk->a[stk->atop_id - 1] = temp;
	}
}
void	sb_do(stacks *stk)
{
	int temp;
	
	if (stk->btop_id > 0)
	{
		temp = stk->b[stk->btop_id];
		stk->b[stk->btop_id] = stk->b[stk->btop_id - 1];
		stk->b[stk->btop_id - 1] = temp;
	}
}

void	ss_do(stacks *stk)
{
	sa_do(stk);
	sb_do(stk);
}