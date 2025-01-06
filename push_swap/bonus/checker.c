/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:42 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/06 15:23:28 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	main(int argc, char **argv)
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	if (exe_intructions(stk))
		return (free_stacks(stk), 1);
	check_ok(stk);
	return (free_stacks(stk), 0);
}

int	exe_intructions(t_stacks *stk)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (!command_assign(command, stk))
			return (free(command), 1);
		free(command);
	}
	return (0);
}

int	command_assign(char *command, t_stacks *stk)
{
	if (!ft_strncmp(command, "sa\n", 3))
		sa_do(stk, 0);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb_do(stk, 0);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss_do(stk, 0);
	else if (!ft_strncmp(command, "pa\n", 3))
		pa_do(stk, 0);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb_do(stk, 0);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra_do(stk, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb_do(stk, 0);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr_do(stk, 0);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra_do(stk, 0);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb_do(stk, 0);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr_do(stk, 0);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

void	check_ok(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id) && stk->btop_id == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
