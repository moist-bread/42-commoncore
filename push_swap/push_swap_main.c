/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/12 00:06:38 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	print_both_stacks(stk);
	sort_stack(stk);
	print_both_stacks(stk);
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
	free_stacks(stk);
	return (0);
}
