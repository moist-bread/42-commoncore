/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 14:52:23 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *stack, int top_idx)
{
	if (top_idx < 0)
		ft_printf("|empty| (%i)\n", top_idx);
	while (top_idx >= 0)
	{
		ft_printf("|%i| (%i)\n", stack[top_idx], top_idx);
		top_idx--;
	}
	ft_printf("\n");
}

void	print_both_stacks(t_stacks *stk)
{
	print_stack(stk->a, stk->atop_id);
	print_stack(stk->b, stk->btop_id);
}

void	print_dists(int id_a, int id_b, int dist_a, int dist_b)
{
	ft_printf("%d(id_a) ", id_a);
	ft_printf("%d(id_b) ", id_b);
	ft_printf("%d(dist_a) ", dist_a);
	ft_printf("%d(dist_b)\n", dist_b);
}

void	print_moves(t_moves *mover, t_stacks *stk)
{
	ft_printf("%d(cur move)\n", mover->cur_move);
	ft_printf("%d(cur rot)\n", mover->cur_rot);
	ft_printf("%d(bst move)\n", mover->bst_move);
	ft_printf("%d(bst rot)\n", mover->bst_rot);
	ft_printf("%d(bst id a)\n", mover->bst_id_a);
	ft_printf("%d(bst id a nb) !!\n", stk->a[mover->bst_id_a]);
	ft_printf("%d(bst id b)\n\n", mover->bst_id_b);
}
