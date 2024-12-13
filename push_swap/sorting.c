/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/13 18:18:23 by rduro-pe         ###   ########.fr       */
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
	rb_do(stk);
	pb_do(stk);
	// pb_do(stk);
	sort_calc(stk, mover);
	execute_move(stk, mover);
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
	int rot;
	
	id_a = stk->atop_id;
	id_b = stk->btop_id;
	mover->bst_moves = 1;
	if (stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[0]) // MAKE WORK FOR THE SAMLLEST NUMBER
	{
		mover->bst_id = id_a;
		return;	
	}
	while (id_a + 1)
	{
		rot = 0;
		id_b = stk->btop_id + 1;		
		while (--id_b >= 0)
		{
			if (id_b != stk->btop_id)
			{	
				if (stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[id_b + 1])
					break;
			}
			else if	(stk->a[id_a] > stk->b[id_b] && stk->a[id_a] < stk->b[0])
				break;
		}
		if (id_a >= ((stk->atop_id + 1) / 2) + ((stk->atop_id + 1) % 2))
		{
			dist_a = stk->atop_id - id_a;
			rot++;
		}
		else
		{
			dist_a = id_a + 1;
			rot--;	
		}
		if (id_b >= ((stk->btop_id + 1) / 2) + ((stk->btop_id + 1) % 2))
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
			mover->cur_moves = dist_a + 1;
			ft_printf("rot %d\n", rot);
		}
		else
			mover->cur_moves = dist_a + dist_b + 1;
		if (id_a == stk->atop_id || mover->bst_moves > mover->cur_moves)
		{
			mover->bst_moves = mover->cur_moves;
			mover->bst_id = id_a;
		}
		ft_printf("%d(cur move)\n", mover->cur_moves);
		ft_printf("%d(bst move)\n", mover->bst_moves);
		ft_printf("%d(bst id)\n\n", mover->bst_id);	
		// if (mover->bst_moves == 2)
		// 	break;
		id_a--;	
	}
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
