/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:14:45 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/28 21:03:38 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_check(int *stk, int top)
{
	int	i;
	int	j;

	i = -1;
	while (++i < top)
	{
		j = 0;
		while (++j + i <= top)
			if (stk[i] < stk[i + j])
				return (0);
	}
	return (1);
}

int	semi_sort_check(int *stk, int top)
{
	int	i;
	int	j;

	i = -1;
	while (++i < top)
	{
		j = 0;
		while (++j + i <= top)
		{
			if (i == 0 && stk[i] < stk[i + j] && stk[top] > stk[0])
			{
				if (!sort_check(stk, j - 1))
					return (0);
				i = j;
				j = 0;
			}
			else if (stk[i] < stk[i + j])
				return (0);
		}
	}
	return (1);
}

t_moves	*set_mover(void)
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
	return (mover);
}

int	dist_calc(int id, int top, t_moves *mover, int flag)
{
	int	dist;

	if (id >= (top + 1) / 2)
	{
		dist = top - id;
		if (flag)
			mover->cur_rot++;
	}
	else
	{
		dist = id + 1;
		if (flag)
			mover->cur_rot--;
	}
	return (dist);
}

void	stack_shift(t_stacks *stk)
{
	t_range	*range;
	t_moves	*mover;
	int		dist;

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
