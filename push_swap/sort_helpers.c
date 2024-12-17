/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:14:45 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/17 12:53:30 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	rev_sort_check(int *stk, int top)
{
	int	i;
	int	j;

	i = -1;
	while (++i < top)
	{
		j = 0;
		while (++j + i <= top)
			if (stk[i] > stk[i + j])
				return (0);
	}
	return (1);
}

void	self_sort(t_stacks *stks, int *stk, int top)
{
	if (top == 1)
		if (!sort_check(stk, top))
			return (sa_do(stks, 1));
	if (!sort_check(stk, top))
	{
		if (stk[top] < stk[top - 1]) // 2 3 1
			rra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] > stk[top - 2]) // 3 1 2
			ra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] < stk[top - 2]) // 2 1 3
			sa_do(stks, 1);
	}
}
// 1 2 3	0
// 1 3 2	2 rra (2 1 3) + sa
// 2 3 1	1 rra
// 2 1 3	1 sa
// 3 2 1	2 ra (2 1 3) + sa
// 3 1 2	1 ra

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
