/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/02 15:20:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_stack(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id))
		return (0);
	if (stk->atop_id <= 2)
		return (self_sort_3(stk, stk->a, stk->atop_id), 0);
	if (stk->atop_id == 4)
		return (self_sort_5(stk));
	if (initial_sort(stk))
		return (1);
	if (!sort_check(stk->a, stk->atop_id))
		if (self_sort_5(stk))
			return (1);
	if (stk->btop_id >= 0)
		if (final_sort(stk))
			return (1);
	return (0);
}

void	self_sort_3(t_stacks *stks, int *stk, int top)
{
	if (top == 1 && !sort_check(stk, top))
		sa_do(stks, 1);
	else if (!sort_check(stk, top))
	{
		if (stk[top] < stk[top - 1])
			rra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] > stk[top - 2])
			ra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] < stk[top - 2])
			sa_do(stks, 1);
	}
}

int	self_sort_5(t_stacks *stk)
{
	while (stk->atop_id > 2)
		pb_do(stk, 1);
	self_sort_3(stk, stk->a, stk->atop_id);
	if (stk->b[0] > stk->b[1])
		sb_do(stk, 1);
	if (final_sort(stk))
		return (1);
	return (0);
}

int	initial_sort(t_stacks *stk)
{
	t_highest	*high;
	t_moves		*mover;

	mover = set_mover();
	if (!mover)
		return (1);
	high = highest_elems(stk);
	if (!high)
		return (free(mover), 1);
	pb_do(stk, 1);
	pb_do(stk, 1);
	while (stk->atop_id >= 5)
	{
		while (stk->a[stk->atop_id] >= high->low_high
			&& stk->a[stk->atop_id] <= high->top_high
			&& stk->atop_id > stk->btop_id)
			ra_do(stk, 1);
		if (sort_calc(stk->atop_id + 1, stk, mover))
			return (free(mover), free(high), 1);
		exe_move(stk, mover);
	}
	return (free(mover), free(high), 0);
}

int	final_sort(t_stacks *stk)
{
	t_range	*range;

	range = stack_range(stk->a, stk->atop_id);
	if (!range)
		return (1);
	if (stk->b[stk->btop_id] < range->high && stk->b[stk->btop_id] > range->low)
		while (stk->b[stk->btop_id] < stk->a[0])
			rra_do(stk, 1);
	while (stk->btop_id >= 0)
		exe_final(stk, range);
	if (stack_shift(stk))
		return (free(range), 1);
	return (free(range), 0);
}
