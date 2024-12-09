/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/09 18:06:38 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_do(t_stacks *stk)
{
	if (stk->btop_id >= 0)
	{
		stk->atop_id++;
		stk->a[stk->atop_id] = stk->b[stk->btop_id];
		stk->b[stk->btop_id] = 0;
		stk->btop_id--;
	}
}

void	pb_do(t_stacks *stk)
{
	if (stk->atop_id >= 0)
	{
		stk->btop_id++;
		stk->b[stk->btop_id] = stk->a[stk->atop_id];
		stk->a[stk->atop_id] = 0;
		stk->atop_id--;
	}
}

void	ra_do(t_stacks *stk)
{
	int	temp;
	int	i;

	if (stk->atop_id > 0)
	{
		i = stk->atop_id;
		temp = stk->a[stk->atop_id];
		while (i > 0)
		{
			stk->a[i] = stk->a[i - 1];
			i--;
		}
		stk->a[0] = temp;
	}
}

void	rb_do(t_stacks *stk)
{
	int	temp;
	int	i;

	if (stk->btop_id > 0)
	{
		i = stk->btop_id;
		temp = stk->b[stk->btop_id];
		while (i > 0)
		{
			stk->b[i] = stk->b[i - 1];
			i--;
		}
		stk->b[0] = temp;
	}
}

void	rr_do(t_stacks *stk)
{
	ra_do(stk);
	rb_do(stk);
}
