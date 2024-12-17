/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/17 12:49:07 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (stk->atop_id >= 0) // WHILE ATOPID BIGGER THAN 2
	{
		sort_calc(stk, mover);
		exe_move(stk, mover);
	}
	// MAKE IT SORT TO THE OTHER SIDE PLS
	free(mover);
}
