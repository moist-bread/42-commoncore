/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/28 22:13:53 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id))
		return ;
	if (stk->atop_id <= 2)
		return (self_sort_3(stk, stk->a, stk->atop_id));
	if (stk->atop_id == 4)
		return (self_sort_5(stk, stk->a, stk->atop_id));
	initial_sort(stk);
	if (!sort_check(stk->a, stk->atop_id))
		self_sort_5(stk, stk->a, stk->atop_id);
	final_sort(stk);
}

void	self_sort_3(t_stacks *stks, int *stk, int top)
{
	if (top == 1)
		if (!sort_check(stk, top))
			return (sa_do(stks, 1));
	if (!sort_check(stk, top))
	{
		if (stk[top] < stk[top - 1])
			rra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] > stk[top - 2])
			ra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] < stk[top - 2])
			sa_do(stks, 1);
	}
}
// 1 2 3	0
// 1 3 2	2 rra (2 1 3) + sa
// 2 3 1	1 rra
// 2 1 3	1 sa
// 3 2 1	2 ra (2 1 3) + sa
// 3 1 2	1 ra

void	self_sort_5(t_stacks *stks, int *stk, int top)
{
	t_range	*range;

	range = stack_range(stk, top);
	if (!range)
		return ;
	while (!semi_sort_check(stk, top))
	{
		if ((stk[top] < range->high && stk[top] > stk[top - 1])
			|| (stk[top] == range->high && stk[top - 1] > stk[0]))
			sa_do(stks, 1);
		else if ((stk[0] < range->high && stk[0] > stk[top])
			|| (stk[0] == range->high && stk[top] > stk[1]))
			rra_do(stks, 1);
		else
			ra_do(stks, 1);
	}
	stack_shift(stks);
	free(range);
}

void	initial_sort(t_stacks *stk)
{
	t_highest	*high;
	t_moves		*mover;

	mover = set_mover();
	if (!mover)
		return ;
	high = highest_elems(stk);
	if (!high)
		return (free(mover));
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id >= 5)
	{
		while (stk->a[stk->atop_id] >= high->low_high
			&& stk->a[stk->atop_id] <= high->top_high
			&& stk->atop_id > stk->btop_id)
			ra_do(stk, 1);
		sort_calc(stk->atop_id + 1, stk, mover, high);
		exe_move(stk, mover);
	}
	free(mover);
	free(high);
}

void	final_sort(t_stacks *stk)
{
	t_range	*range;

	/* int		i;
	i = 0; */
	range = stack_range(stk->a, stk->atop_id);
	if (!range)
		return ;
	if (stk->b[stk->btop_id] < range->high && stk->b[stk->btop_id] > range->low)
		while (stk->b[stk->btop_id] < stk->a[0])
			rra_do(stk, 1);
	while (stk->btop_id >= 0)
	{
		if ((stk->b[stk->btop_id] > stk->a[0]
				&& stk->b[stk->btop_id] < stk->a[stk->atop_id])
			|| (stk->b[stk->btop_id] < range->low
				&& stk->b[stk->btop_id] < stk->a[stk->atop_id]
				&& !(stk->a[0] == range->low))
			|| (stk->b[stk->btop_id] > range->high && stk->a[0] == range->high))
		{
			if (stk->b[stk->btop_id] < range->low)
				range->low = stk->b[stk->btop_id];
			else if (stk->b[stk->btop_id] > range->high)
				range->high = stk->b[stk->btop_id];
			pa_do(stk);
		}
		else
		{
			rra_do(stk, 1);
			/* i++;
			if (i == 100)
				return ; */
		}
	}
	free(range);
	stack_shift(stk);
}
