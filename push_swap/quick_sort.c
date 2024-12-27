/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:09:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:22 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_highest	*highest_elems(t_stacks *stk)
{
	t_highest	*highest;
	int			*quicksrt;
	int			pivot;
	int			i;

	quicksrt = malloc((stk->atop_id + 1) * sizeof(int));
	if (!quicksrt)
		return (NULL);
	highest = malloc(sizeof(t_highest));
	if (!highest)
		return (NULL);
	i = -1;
	while (++i <= stk->atop_id)
		quicksrt[i] = stk->a[i];
	// print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	pivot = pivot_picker(quicksrt, stk->atop_id);
	// print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	// ft_printf("%d(PIVOT)\n", pivot);
	quick_sort(quicksrt, 0, pivot);
	// print_stack(quicksrt, stk->atop_id); // PRINTING FT !!
	highest->top_high = quicksrt[stk->atop_id];
	highest->low_high = quicksrt[(stk->atop_id / 4) * 3];
	free(quicksrt);
	return (highest);
}

int	pivot_picker(int *qs, int last)
{
	int	mid;

	mid = last / 2;
	if (qs[0] > qs[mid] && qs[0] > qs[last])
		ft_swap(&qs[0], &qs[mid]);
	if (qs[last] > qs[0] && qs[last] > qs[mid])
		ft_swap(&qs[mid], &qs[last]);
	if (qs[0] > qs[last])
		ft_swap(&qs[0], &qs[last]);
	return (last);
}

void	ft_swap(int *a, int *b)
{
	int	swp;

	// ft_printf("%d(a) %d(b)\n", *a, *b); // PRINTING FT !!
	swp = *a;
	*a = *b;
	*b = swp;
	// ft_printf("%d(a) %d(b)\n\n", *a, *b); // PRINTING FT !!
}

void	quick_sort(int *qs, int start, int pivot)
{
	int	i;
	int	j;

	// ft_printf("recuriva\n");
	// print_stack(qs, 13);
	if (start < pivot)
	{
		i = start;
		j = start - 1;
		while (i <= pivot)
		{
			if (qs[i] <= qs[pivot])
			{
				j++;
				// ft_printf("in w/ %d[%d] %d[%d]\n", qs[i], i, qs[j], j);
				if (qs[i] < qs[j])
					ft_swap(&qs[i], &qs[j]);
			}
			i++;
		}
		// ft_swap(&qs[j], &qs[pivot]);
		quick_sort(qs, start, j - 1);
		quick_sort(qs, j + 1, pivot);
	}
}
