/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:49:09 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/06 15:54:54 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_calc(int id_a, t_stacks *stk, t_moves *mover)
{
	int		id_b;
	int		dist_a;
	int		dist_b;
	t_range	*range;

	mover->bst_move = 1;
	range = stack_range(stk->b, stk->btop_id);
	if (!range)
		return (1);
	while (id_a--)
	{
		mover->cur_rot = 0;
		id_b = place_finder(id_a, stk, range);
		dist_a = dist_calc(id_a, stk->atop_id, mover, 1);
		dist_b = dist_calc(id_b, stk->btop_id, mover, 1);
		mover->cur_move = curmov_calc(dist_a, dist_b, stk->btop_id, mover);
		if (id_a == stk->atop_id || mover->cur_move < mover->bst_move)
			if (is_the_best(id_a, id_b, mover))
				break ;
	}
	return (free(range), 0);
}

t_range	*stack_range(int *stk, int top_id)
{
	int		i;
	t_range	*range;

	range = malloc(sizeof(t_range));
	if (!range)
		return (NULL);
	i = 0;
	range->high = stk[0];
	range->low = stk[0];
	range->high_id = 0;
	range->low_id = 0;
	while (++i <= top_id)
	{
		if (stk[i] > range->high)
		{
			range->high = stk[i];
			range->high_id = i;
		}
		else if (stk[i] < range->low)
		{
			range->low = stk[i];
			range->low_id = i;
		}
	}
	return (range);
}

int	place_finder(int id_a, t_stacks *stk, t_range *range)
{
	int	id_b;

	id_b = stk->btop_id + 1;
	if (stk->a[id_a] < range->low || stk->a[id_a] > range->high)
		id_b = range->high_id;
	else
	{
		while (--id_b >= 0)
		{
			if (id_b != stk->btop_id && stk->a[id_a] > stk->b[id_b]
				&& stk->a[id_a] < stk->b[id_b + 1])
				break ;
			else if (stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[0])
				break ;
		}
	}
	return (id_b);
}

int	curmov_calc(int dist_a, int dist_b, int bt, t_moves *mover)
{
	if (mover->cur_rot == 2 || mover->cur_rot == -2 || bt == 1)
	{
		if (dist_b > dist_a)
			dist_a = dist_b;
		return (dist_a + 1);
	}
	else
		return (dist_a + dist_b + 1);
}

int	is_the_best(int id_a, int id_b, t_moves *mover)
{
	mover->bst_move = mover->cur_move;
	mover->bst_rot = mover->cur_rot;
	mover->bst_id_a = id_a;
	mover->bst_id_b = id_b;
	if (mover->bst_move <= 2)
		return (1);
	return (0);
}
