/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:50 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void final_sort(t_stacks *stk);

void	sort_stack(t_stacks *stk)
{
	t_moves	*mover;

	if (sort_check(stk->a, stk->atop_id))
		return ;
	if (stk->atop_id <= 2)
		return (self_sort(stk, stk->a, stk->atop_id));
	mover = malloc(sizeof(t_moves));
	if (!mover)
		return ;
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id >= 2) // WHILE ATOPID BIGGER THAN 2
	{
		sort_calc(stk, mover);
		exe_move(stk, mover);
		//print_both_stacks(stk);
	}
	self_sort(stk, stk->a, stk->atop_id);
	final_sort(stk); // MAKE IT SORT TO THE OTHER SIDE PLS
	free(mover);
}

void final_sort(t_stacks *stk)
{
	while (stk->b[stk->btop_id] > stk->b[stk->btop_id - 1])
		rb_do(stk, 1);
	rb_do(stk, 1);
	while (stk->btop_id >= 0)
		pa_do(stk);
	/* while (stk->btop_id >= 0)
	{
		if(stk->a[stk->atop_id] < stk->b[stk->btop_id])
			ra_do(stk, 1);
		while(stk->a[stk->atop_id] > stk->b[stk->btop_id] && stk->a[0] < stk->b[stk->btop_id])
			pa_do(stk);
		if(stk->btop_id > 0)
			rra_do(stk, 1); // FIX RRA IFF
	} */
}