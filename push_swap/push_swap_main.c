/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/18 13:09:22 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	print_both_stacks(stk); // PRINTING FT !!
	sort_stack(stk);
	//print_both_stacks(stk); // PRINTING FT !!
	// ft_printf("(args)%i\n", argc);
	// ra_do(stk);
	// print_both_stacks(stk);
	// pb_do(stk);
	// pb_do(stk);
	// print_both_stacks(stk);
	// ss_do(stk);
	// print_both_stacks(stk);
	// pa_do(stk);
	// print_both_stacks(stk);
	// t_range *range = stack_range(stk->a, stk->atop_id);
	// ft_printf("high: %d(%d) | low: %d(%d)\n", range->high, range->high_id, range->low, range->low_id);
	free_stacks(stk);
	return (0);
}
