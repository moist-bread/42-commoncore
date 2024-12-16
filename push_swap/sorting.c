/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/16 17:00:45 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stk)
{
	t_moves	*mover;

	if (sort_check(stk->a, stk->atop_id))
		return ;
	if (stk->atop_id <= 2)
	{
		self_sort(stk, stk->a, stk->atop_id);
		return ;
	}
	mover = malloc(sizeof(t_moves));
	// if (!mover)
	// 	return (0);
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id >= 0) // WHILE ATOPID BIGGER THAN 2
	{	
		sort_calc(stk, mover);
		exe_move(stk, mover->bst_id_a, mover->bst_id_b);
	}
	free(mover);
}

//  100 30 25 15 10 5
// 100

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

void	sort_calc(t_stacks *stk, t_moves *mover)
{
	int	id_a;
	int	id_b;
	int	dist_a;
	int	dist_b;
	int	rot;
	t_range	*range;

	id_a = stk->atop_id;
	id_b = stk->btop_id;
	mover->bst_move = 1;
	range = stack_range(stk->b, stk->btop_id);
	while (id_a + 1)
	{
		rot = 0;
		id_b = stk->btop_id + 1;
		
		if(stk->a[id_a] < range->low || stk->a[id_a] > range->high)
			id_b = range->high_id;	
		else
		{	
			while (--id_b >= 0)
			{
				if (id_b != stk->btop_id && stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[id_b + 1])
					break ;
				else if (stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[0])
					break ;
			}
		}
		if (id_a >= (stk->atop_id + 1) / 2)
		{
			dist_a = stk->atop_id - id_a;
			rot++;
		}
		else
		{
			dist_a = id_a + 1;
			rot--;
		}
		if (id_b >= (stk->btop_id + 1) / 2)
		{
			dist_b = stk->btop_id - id_b;
			rot++;
		}
		else
		{
			dist_b = id_b + 1;
			rot--;
		}
		ft_printf("%d(id_a)\n", id_a);
		ft_printf("%d(id_b)\n", id_b);
		ft_printf("%d(dist_a)\n", dist_a);
		ft_printf("%d(dist_b)\n", dist_b);
		if (rot == 2 || rot == -2 || stk->btop_id == 1)
		{
			if (dist_b > dist_a)
				dist_a = dist_b;
			mover->cur_move = dist_a + 1;
			ft_printf("rot %d\n", rot);
		}
		else
			mover->cur_move = dist_a + dist_b + 1;
		if (id_a == stk->atop_id || mover->bst_move > mover->cur_move)
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
		id_a--;
	}
	free(range);
}

t_range *stack_range(int *stk, int top_id)
{
	int i;
	t_range *range;
	
	range = malloc(sizeof(t_range));
	if (!range)
		return (NULL);
	i = 0;
	range->high = stk[0];
	range->low = stk[0];
	while(++i <= top_id)
	{
		if(stk[i] > range->high)
		{
			range->high = stk[i];
			range->high_id = i;	
		}
		else if(stk[i] < range->low)
		{
			range->low = stk[i];
			range->low_id = i;	
		}
	}
	return(range);
}

void	self_sort(t_stacks *stks, int *stk, int top)
{
	if (top == 1)
		if (!sort_check(stk, top))
		{
			sa_do(stks, 1);
			return ;
		}
	if (!sort_check(stk, top))
	{
		if (stk[top] < stk[top - 1]) // 2 3 1
			rra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] > stk[top - 2]) // 3 1 2
			ra_do(stks, 1);
		if (stk[top] > stk[top - 1] && stk[top] < stk[top - 2]) // 2 1 3
			sa_do(stks, 1);
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
