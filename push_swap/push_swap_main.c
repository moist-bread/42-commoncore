/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/20 19:09:17 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	// print_both_stacks(stk); // PRINTING FT !!
	//sort_stack(stk);
	//self_sort_5(stk, stk->a, stk->atop_id);
	int semi = semi_sort_check(stk->a, stk->atop_id);
	ft_printf("%d\n", semi);
	print_both_stacks(stk); // PRINTING FT !!
	free_stacks(stk);
	return (0);
}
