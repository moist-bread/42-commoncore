/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:13:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/09 18:04:46 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(char *argv[])
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

int	int_check(char argv[])
{
	int	j;

	j = -1;
	if (argv[0] == '-' || argv[0] == '+')
		j++;
	while (argv[++j])
		if (!ft_isdigit(argv[j]))
			return (1);
	if (!overflow_check(argv))
		return (1);
	return (0);
}

int	overflow_check(char *str)
{
	long	result;
	long	verif;
	int		sign;

	sign = 0;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign)
		result = -result;
	verif = result * 50;
	if (verif / 50 != result) // long overflow
		return (0);
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (1);
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
