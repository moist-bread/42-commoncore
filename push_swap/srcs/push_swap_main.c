/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/02 11:56:21 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	//print_both_stacks(stk);
	if (sort_stack(stk))
		return (free_stacks(stk), 1);
	//print_both_stacks(stk);
	return (free_stacks(stk), 0);
}
