/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:40:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/30 12:46:09 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exe_move(t_stacks *stk, t_moves *mover)
{
	int	dist_a;
	int	dist_b;

	dist_a = dist_calc(mover->bst_id_a, stk->atop_id, mover, 0);
	dist_b = dist_calc(mover->bst_id_b, stk->btop_id, mover, 0);
	while (mover->bst_rot == 2 && dist_a && dist_b)
	{
		rr_do(stk, 1);
		dist_a--;
		dist_b--;
	}
	while (mover->bst_rot == -2 && dist_a && dist_b)
	{
		rrr_do(stk, 1);
		dist_a--;
		dist_b--;
	}
	exe_rot(&dist_a, mover->bst_id_a, stk, 'a');
	exe_rot(&dist_b, mover->bst_id_b, stk, 'b');
	pb_do(stk, 1);
}

void	exe_rot(int *dist, int bst_id, t_stacks *stk, int flag)
{
	int	top_id;

	if (flag == 'a')
		top_id = stk->atop_id;
	else
		top_id = stk->btop_id;
	while (*dist)
	{
		if (bst_id >= (top_id + 1) / 2)
		{
			if (flag == 'a')
				ra_do(stk, 1);
			else
				rb_do(stk, 1);
		}
		else
		{
			if (flag == 'a')
				rra_do(stk, 1);
			else
				rrb_do(stk, 1);
		}
		(*dist)--;
	}
}

void	exe_final(t_stacks *stk, t_range *range)
{
	if ((stk->b[stk->btop_id] > stk->a[0]
			&& stk->b[stk->btop_id] < stk->a[stk->atop_id])
		|| (stk->b[stk->btop_id] < range->low
			&& stk->a[stk->atop_id] == range->low)
		|| (stk->b[stk->btop_id] > range->high && stk->a[0] == range->high))
	{
		if (stk->b[stk->btop_id] < range->low)
			range->low = stk->b[stk->btop_id];
		else if (stk->b[stk->btop_id] > range->high)
			range->high = stk->b[stk->btop_id];
		pa_do(stk, 1);
	}
	else
		rra_do(stk, 1);
}
