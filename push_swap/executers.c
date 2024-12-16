/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:40:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/16 17:40:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	exe_move(t_stacks *stk,  int ba, int bb)
{
	int rot;
	int dist_a;
	int dist_b;
	
	rot = 0;
	if (ba >= (stk->atop_id + 1) / 2)
	{
		dist_a = stk->atop_id - ba;
		rot++;
	}
	else
	{
		dist_a = ba + 1;
		rot--;
	}
	if (bb >= (stk->btop_id + 1) / 2)
	{
		dist_b = stk->btop_id - bb;
		rot++;
	}
	else
	{
		dist_b = bb + 1;
		rot--;
	}
	while (rot == 2 && dist_a && dist_b)
	{
		rr_do(stk);
		dist_a--;
		dist_b--;
	}
	while (rot == -2 && dist_a && dist_b)
	{
		rrr_do(stk);
		dist_a--;
		dist_b--;
	}
	while (dist_b)
	{
		if(bb >= (stk->btop_id + 1) / 2)
			rb_do(stk, 1);
		else
			rrb_do(stk, 1);
		dist_b--;
	}
	while (dist_a)
	{
		if(ba >= (stk->atop_id + 1) / 2)
			ra_do(stk, 1);
		else
			rra_do(stk, 1);
		dist_a--;
	}
	pb_do(stk);
}
