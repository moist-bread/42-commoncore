/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:09:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 14:49:13 by rduro-pe         ###   ########.fr       */
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
	pivot = pivot_picker(quicksrt, stk->atop_id);
	quick_sort(quicksrt, 0, pivot);
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

	swp = *a;
	*a = *b;
	*b = swp;
}

void	quick_sort(int *qs, int start, int pivot)
{
	int	i;
	int	j;

	if (start < pivot)
	{
		i = start;
		j = start - 1;
		while (i <= pivot)
		{
			if (qs[i] <= qs[pivot])
			{
				j++;
				if (qs[i] < qs[j])
					ft_swap(&qs[i], &qs[j]);
			}
			i++;
		}
		quick_sort(qs, start, j - 1);
		quick_sort(qs, j + 1, pivot);
	}
}
