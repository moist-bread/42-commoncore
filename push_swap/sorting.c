/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/12 12:40:13 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_calc(t_stacks *stk);

void	sort_stack(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id))
		return;
	if (stk->atop_id <= 2)
		self_sort(stk, stk->a, stk->atop_id);
	pb_do(stk);
	pb_do(stk);
	sort_calc(stk);
	
}

void	sort_calc(t_stacks *stk)
{
	(void)stk;
}

void	self_sort(t_stacks *stks, int *stk, int top)
{
	if (top == 1)
		if (!sort_check(stk, top))
		{
			sa_do(stks);
			return;
		}
	if (!sort_check(stk, top))
	{
		if (stk[top] < stk[top - 1]) // 2 3 1
			rra_do(stks);
		if (stk[top] > stk[top - 1] && stk[top] > stk[top - 2]) // 3 1 2
			ra_do(stks);
		if (stk[top] > stk[top - 1] && stk[top] < stk[top - 2]) // 2 1 3
			sa_do(stks);
		// ft_printf("entrou\n");
	}
	// 1 2 3	0
	// 1 3 2	2 rra (2 1 3) + sa
	// 2 3 1	1 rra
	// 2 1 3	1 sa
	// 3 2 1	2 ra (2 1 3) + sa
	// 3 1 2	1 ra
}

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
