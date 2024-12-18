/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/18 13:41:24 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void final_sort(t_stacks *stk);
void highest_elems(t_stacks	*stk);
int pivot_picker(int *qs, int last);
void	ft_swap(int *a, int *b);

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
	highest_elems(stk); // QUICK SORT 
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id > 2) // WHILE ATOPID BIGGER THAN 2
	{
		sort_calc(stk, mover);
		exe_move(stk, mover);
		//print_both_stacks(stk);
	}
	if (!sort_check(stk->a, stk->atop_id))
		self_sort(stk, stk->a, stk->atop_id);
	//final_sort(stk); // MAKE IT SORT TO THE OTHER SIDE PLS
	free(mover);
}

void highest_elems(t_stacks	*stk)
{
	int *quicksrt;
	int pivot;
	int i;
	
	quicksrt = malloc((stk->atop_id + 1) * sizeof(int));
	if (!quicksrt)
		return ;
	i = -1;
	while (++i <= stk->atop_id)
		quicksrt[i] = stk->a[i];
	
	print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	pivot = pivot_picker(quicksrt, stk->atop_id);
	print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	free(quicksrt);
}

int pivot_picker(int *qs, int last)
{
	int mid;

	mid = last / 2;
	if (qs[0] > qs[last])
		ft_swap(&qs[0], &qs[last]);
	if (qs[0] > qs[mid])
		ft_swap(&qs[0], &qs[mid]);
	if(qs[mid] > qs[last])
		ft_swap(&qs[mid], &qs[last]);
	return(mid);
}

void	ft_swap(int *a, int *b)
{
	int	swp;

	ft_printf("%d(a) %d(b)\n", *a, *b); // PRINTING FT !!
	swp = *a;
	*a = *b;
	*b = swp;
	ft_printf("%d(a) %d(b)\n\n", *a, *b); // PRINTING FT !!
}

void final_sort(t_stacks *stk)
{
	/* while (stk->b[stk->btop_id] > stk->b[stk->btop_id - 1])
		rb_do(stk, 1);
	rb_do(stk, 1);
	while (stk->btop_id >= 0)
		pa_do(stk); */
	/* while (stk->btop_id >= 0)
	{
		if(stk->a[stk->atop_id] < stk->b[stk->btop_id])
			ra_do(stk, 1);
		while(stk->a[stk->atop_id] > stk->b[stk->btop_id] && stk->a[0] < stk->b[stk->btop_id])
			pa_do(stk);
		if(stk->btop_id > 0)
			rra_do(stk, 1); // FIX RRA IFF
	} */
	(void)stk;
}