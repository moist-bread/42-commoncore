/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:36:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/18 19:06:53 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initial_sort(t_stacks *stk);

void	sort_stack(t_stacks *stk)
{

	if (sort_check(stk->a, stk->atop_id))
		return ;
	if (stk->atop_id <= 2)
		return (self_sort(stk, stk->a, stk->atop_id));
	initial_sort(stk);
	if (!sort_check(stk->a, stk->atop_id))
		self_sort(stk, stk->a, stk->atop_id);
	final_sort(stk); // MAKE IT SORT TO THE OTHER SIDE PLS
}

void initial_sort(t_stacks *stk)
{
	t_highest *highest;
	t_moves	*mover;

	mover = malloc(sizeof(t_moves));
	if (!mover)
		return (free(mover)) ;
	highest = highest_elems(stk); // QUICK SORT 
	if (!highest)
		return ;
	pb_do(stk);
	pb_do(stk);
	while (stk->atop_id >= 0) // WHILE ATOPID BIGGER THAN 2
	{
		//ft_printf("num: %d\n", stk->a[stk->atop_id]); // PRINTING FT !!
		/* while (stk->a[stk->atop_id] >= highest->low_high && stk->a[stk->atop_id] <= highest->top_high)
		{
			//ft_printf("HIGH NUM (%d)!!\n", stk->a[stk->atop_id]); // PRINTING FT !!
			ra_do(stk, 1);
		} */
		sort_calc(stk, mover);
		exe_move(stk, mover);
		//print_both_stacks(stk); // PRINTING FT !!
	}
	free(mover);
	free(highest);
}

t_highest *highest_elems(t_stacks	*stk)
{
	t_highest *highest;
	int *quicksrt;
	int pivot;
	int i;
	
	quicksrt = malloc((stk->atop_id + 1) * sizeof(int));
	if (!quicksrt)
		return (NULL);
	highest = malloc(sizeof(t_highest));
	if (!highest)
		return (NULL);
	i = -1;
	while (++i <= stk->atop_id)
		quicksrt[i] = stk->a[i];
	
	//print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	pivot = pivot_picker(quicksrt, stk->atop_id);
	//print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	//ft_printf("%d(PIVOT)\n", pivot);
	quick_sort(quicksrt, 0, pivot);
	//print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	highest->top_high = quicksrt[stk->atop_id];
	highest->low_high = quicksrt[(stk->atop_id / 4) * 2];
	free(quicksrt);
	return (highest);
}

void quick_sort(int *qs, int start, int pivot)
{
	int i;
	int j;
	// ft_printf("recuriva\n");
	// print_stack(qs, 13);
	if (start < pivot)
	{
		i = start;
		j = start - 1;
		while(i <= pivot)
		{
			if(qs[i] <= qs[pivot])
			{
				j++;
				//ft_printf("in w/ %d[%d] %d[%d]\n", qs[i], i, qs[j], j);
				if(qs[i] < qs[j])
					ft_swap(&qs[i], &qs[j]);
			}
			i++;
		}
		//ft_swap(&qs[j], &qs[pivot]);
		quick_sort(qs, start, j - 1);
		quick_sort(qs, j + 1, pivot);
	}
}

int pivot_picker(int *qs, int last)
{
	int mid;

	mid = last / 2;
	if (qs[0] > qs[mid] && qs[0] > qs[last])
		ft_swap(&qs[0], &qs[mid]);
	if (qs[last] > qs[0] && qs[last] > qs[mid])
		ft_swap(&qs[mid], &qs[last]);	
	if (qs[0] > qs[last])
		ft_swap(&qs[0], &qs[last]);
	return(last);
}

void	ft_swap(int *a, int *b)
{
	int	swp;

	//ft_printf("%d(a) %d(b)\n", *a, *b); // PRINTING FT !!
	swp = *a;
	*a = *b;
	*b = swp;
	//ft_printf("%d(a) %d(b)\n\n", *a, *b); // PRINTING FT !!
}

void final_sort(t_stacks *stk)
{
	while (stk->b[stk->btop_id] > stk->b[stk->btop_id - 1])
		rb_do(stk, 1);
	rb_do(stk, 1);
	while (stk->btop_id >= 0)
		pa_do(stk);
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