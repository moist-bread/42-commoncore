/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/12 15:31:37 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_calc(t_stacks *stk, t_moves *mover);

void	sort_stack(t_stacks *stk)
{
	t_moves *mover;
	
	if (sort_check(stk->a, stk->atop_id))
		return;
	if (stk->atop_id <= 2)
	{
		self_sort(stk, stk->a, stk->atop_id);
		return;
	}
	mover = malloc(sizeof(t_moves));
	pb_do(stk);
	pb_do(stk);
	sort_calc(stk, mover);
	free(mover);
}

// 40 35 30 25 15 10 5
// 20

void	sort_calc(t_stacks *stk, t_moves *mover)
{
	int id_a;
	int id_b;
	int dist_a;
	int dist_b;
	
	id_a = stk->atop_id;
	id_b = stk->btop_id;
	mover->bst_moves = 1;
	if (stk->a[id_a] > stk->b[id_b] || stk->a[id_a] < stk->b[0])
	{
		mover->bst_id = id_a;
		return;	
	}
	//mover->moves = 0;
	while (--id_b >= 0)
		if (stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[id_b + 1])
			break;	 
	dist_a = stk->atop_id / 2 - id_a;
	dist_b = stk->btop_id / 2 - id_b;
	if (dist_a < 0 && dist_b < 0)
	{
		if (dist_b < dist_a)
			dist_a = dist_b;	
		mover->cur_moves = -dist_a + 1;
	}
	if (dist_a >= 0 && dist_b >= 0)
	{
		if (dist_b > dist_a)
			dist_a = dist_b;	
		mover->cur_moves = dist_a + 1;
	}
	//	if(stk->atop_id / 2 - id_a)  = amount of ra
	//	if((12 / 2 - 10 (= -4)) < 0); (12 / 2 - 10) * -1  = amount of ra; else = amount of rra; 		
	//rev_sort_check(stk->b, stk->btop_id);
	
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
