/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/19 16:52:25 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*set_mover();

void	sort_stack(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id))
		return ;
	if (stk->atop_id <= 2)
		return (self_sort(stk, stk->a, stk->atop_id));
	initial_sort(stk);
	if (!sort_check(stk->a, stk->atop_id))
		self_sort(stk, stk->a, stk->atop_id);
	//print_both_stacks(stk); // PRINTING FT !!
	final_sort(stk);        // MAKE IT SORT TO THE OTHER SIDE PLS
}

void	initial_sort(t_stacks *stk)
{
	t_highest	*highest;
	t_moves		*mover;

	mover = set_mover();
	if (!mover)
		return ;
	highest = highest_elems(stk); // QUICK SORT
	if (!highest)
		return (free(mover));
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id >= 3) // WHILE ATOPID BIGGER THAN 2
	{
		// ft_printf("num: %d\n", stk->a[stk->atop_id]); // PRINTING FT !!
		/* while (stk->a[stk->atop_id] >= highest->low_high
			&& stk->a[stk->atop_id] <= highest->top_high)
		{
			//ft_printf("HIGH NUM (%d)!!\n", stk->a[stk->atop_id]);
				// PRINTING FT !!
			ra_do(stk, 1);
		} */
		sort_calc(stk, mover);
		exe_move(stk, mover);
		// print_both_stacks(stk); // PRINTING FT !!
	}
	free(mover);
	free(highest);
}

void	final_sort(t_stacks *stk)
{
	t_range	*range;
	t_moves	*mover;
	int		dist;

	range = stack_range(stk->a, stk->atop_id);
	if (!range)
		return ;
	if(stk->b[stk->btop_id] < range->high && stk->b[stk->btop_id] > range->low)
		while (stk->b[stk->btop_id] < stk->a[0])
			rra_do(stk, 1);
	while (stk->btop_id >= 0)
	{
		if (!(stk->b[stk->btop_id] < range->low))
		{
			while (stk->b[stk->btop_id] > stk->a[0])
			{
				pa_do(stk);
				if (stk->btop_id < 0)
					break;
			}
			rra_do(stk, 1);
		}
		if (stk->btop_id >= 0)
			while (stk->b[stk->btop_id] < range->low && stk->btop_id >= 0)
				pa_do(stk);
	}
	free(range);
	range = stack_range(stk->a, stk->atop_id);
	if (!range)
		return ;
	mover = set_mover();
	if (!mover)
		return (free(range));
	dist = dist_calc(range->low_id, stk->atop_id, mover, 1);
	while (dist--)
	{
		if (mover->cur_rot == 1)
			ra_do(stk, 1);
		else
			rra_do(stk, 1);
	}
	free(mover);
	free(range);
}

t_moves	*set_mover()
{
	t_moves	*mover;

	mover = malloc(sizeof(t_moves));
	if (!mover)
		return (NULL);
	mover->bst_id_a = 0;
	mover->bst_id_b = 0;
	mover->bst_move = 1;
	mover->bst_rot = 0;
	mover->cur_move = 1;
	mover->cur_rot = 0;
	return(mover);
}

/* while (stk->b[stk->btop_id] > stk->b[stk->btop_id - 1])
	rb_do(stk, 1);
rb_do(stk, 1);
while (stk->btop_id >= 0)
	pa_do(stk); */
/* while (stk->btop_id >= 0)
{
	if(stk->a[stk->atop_id] < stk->b[stk->btop_id])
		ra_do(stk, 1);
	while(stk->a[stk->atop_id] > stk->b[stk->btop_id]
		&& stk->a[0] < stk->b[stk->btop_id])
		pa_do(stk);
	if(stk->btop_id > 0)
		rra_do(stk, 1); // FIX RRA IFF
} */