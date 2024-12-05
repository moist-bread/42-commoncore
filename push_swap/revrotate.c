/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:39:30 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/05 17:40:41 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_do(stacks *stk)
{
	int temp;
	int i;
	
	if (stk->atop_id > 0)
	{
		i = 0;
		temp = stk->a[0];
		while(i < stk->atop_id)
		{
			stk->a[i] = stk->a[i + 1];
			i++;	
		}
		stk->a[stk->atop_id] = temp;
	}
}

void	rrb_do(stacks *stk)
{
	int temp;
	int i;
	
	if (stk->btop_id > 0)
	{
		i = 0;
		temp = stk->b[0];
		while(i < stk->btop_id)
		{
			stk->b[i] = stk->b[i + 1];
			i++;	
		}
		stk->b[stk->btop_id] = temp;
	}
}

void	rrr_do(stacks *stk)
{
	rra_do(stk);
	rrb_do(stk);
}