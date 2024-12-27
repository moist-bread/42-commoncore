/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:13:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/27 16:46:08 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	input_processer(int argc, char **argv, t_stacks **stk, int spt)
{
	char	**args;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !(++spt))
			return (1);
	}
	else
		args = &argv[1];
	argc = arg_counter(argc, args);
	if (argc <= 1)
		return (free_args(args, argc, spt));
	if (input_check(args))
		return (free_args(args, argc, spt));
	*stk = make_stacks(argc, args);
	if (!*stk)
		return (free_args(args, argc, spt));
	free_args(args, argc, spt);
	if (repeat_check(*stk))
		return (1);
	return (0);
}

int	input_check(char **argv)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (argv[i] && !error)
		error = int_check(argv[i++]);
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

int	int_check(char *argv)
{
	int	j;

	j = -1;
	if (argv[0] == '-' || argv[0] == '+')
		j++;
	while (argv[++j])
		if (!ft_isdigit(argv[j]))
			return (1);
	if (overflow_check(argv) || !*argv)
		return (1);
	return (0);
}

int	overflow_check(char *str)
{
	long	result;
	int		sign;

	sign = 0;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9') && result < 2147483648)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign)
		result = -result;
	if (result < -2147483648 || result > 2147483647)
		return (1);
	return (0);
}

int	repeat_check(t_stacks *stk)
{
	int	rep;
	int	i;
	int	j;

	rep = 0;
	i = 0;
	while (i < stk->atop_id && !rep)
	{
		j = 1;
		while (i + j <= stk->atop_id && !rep)
			if (stk->a[i] == stk->a[i + j++])
				rep = 1;
		i++;
	}
	if (rep)
	{
		free_stacks(stk);
		write(2, "Error\n", 6);
	}
	return (rep);
}
