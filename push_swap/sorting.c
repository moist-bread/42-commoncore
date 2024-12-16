/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:05 by rduro-pe         ###   ########.fr       */
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
		sort_calc(stk->a, stk->atop_id, stk->b, stk->btop_id, mover);
		exe_move(stk, mover->bst_id_a, mover->bst_id_b);
	}
	// MAKE IT SORT TO THE OTHER SIDE PLS
	free(mover);
}

void	sort_calc(int *sta, int at, int *stb, int bt, t_moves *mover)
{
	int	id_a;
	int	id_b;
	int	dist_a;
	int	dist_b;
	int	rot;
	t_range	*range;

	id_a = at + 1;
	mover->bst_move = 1;
	range = stack_range(stb, bt);
	while (id_a--)
	{
		// ADD THE FUCKASS ROTATION TO THE MOVER
		rot = 0;
		id_b = place_finder(sta, id_a, stb, bt, range);
		dist_a = dist_calc(id_a, at, &rot);
		dist_b = dist_calc(id_b, bt, &rot);
		
		
		ft_printf("%d(id_a)\n", id_a);
		ft_printf("%d(id_b)\n", id_b);
		ft_printf("%d(dist_a)\n", dist_a);
		ft_printf("%d(dist_b)\n", dist_b);
		
		// MAKE INTO NEW FT curmove calc
		if (rot == 2 || rot == -2 || bt == 1)
		{
			if (dist_b > dist_a)
				dist_a = dist_b;
			mover->cur_move = dist_a + 1;
			ft_printf("rot %d\n", rot);
		}
		else
			mover->cur_move = dist_a + dist_b + 1;
		// end
		
		if (id_a == at || mover->bst_move > mover->cur_move)
		{
			mover->bst_move = mover->cur_move;
			mover->bst_id_a = id_a;
			mover->bst_id_b = id_b;
		}
		
		
		ft_printf("%d(cur move)\n", mover->cur_move);
		ft_printf("%d(bst move)\n", mover->bst_move);
		ft_printf("%d(bst id a)\n", mover->bst_id_a);
		ft_printf("%d(bst id b)\n\n", mover->bst_id_b);

		
		if (mover->bst_move <= 2)
			break ;
	}
	free(range);
}

int	place_finder(int *sta, int id_a, int *stb, int bt, t_range *range)
{
	int id_b;
	
	id_b = bt + 1;
	if(sta[id_a] < range->low || sta[id_a] > range->high)
		id_b = range->high_id;	
	else
	{	
		while (--id_b >= 0)
		{
			if (id_b != bt && sta[id_a] > stb[id_b] && sta[id_a] < stb[id_b + 1])
				break ;
			else if (sta[id_a] > stb[id_b] && sta[id_a] < stb[0])
				break ;
		}
	}
	return(id_b);
}

int dist_calc(int id, int top, int *rot)
{
	int dist;

	if (id >= (top + 1) / 2)
	{
		dist = top - id;
		(*rot)++;
	}
	else
	{
		dist = id + 1;
		(*rot)--;
	}
	return(dist);
}
