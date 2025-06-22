/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:50:52 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/11 17:35:55 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	int_overflow_check(char *arg, int *arg_n);
static int	ft_iswhitespace(int c);
static int	ft_isdigit(int c);

/// @brief Checks if ARG is an int and stores it in ARG_N
/// @param arg String to be checked
/// @param arg_n Where the number in ARG is to be stored
/// @return 1 if its a integer, 0 if not
int	int_check(char *arg, int *arg_n)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(*arg))
		arg++;
	if (*arg == '-' || *arg == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	while (arg[i] && ft_iswhitespace(arg[i]))
		i++;
	if (arg[i])
		return (0);
	if (int_overflow_check(arg, arg_n))
		return (0);
	return (1);
}

/// @brief Verifies if the number in ARG is within the range of an integer
/// @param arg String to be checked
/// @param arg_n Where the number in ARG is to be stored
/// @return 1 if there's overflow, 0 when there isn't overflow
static int	int_overflow_check(char *arg, int *arg_n)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*arg == '+' || *arg == '-')
		if (arg++ && *(arg - 1) == '-')
			sign = -1;
	while (ft_isdigit(*arg))
	{
		if (num > 2147483648)
			return (1);
		num = num * 10 + (*arg - '0');
		arg++;
	}
	num *= sign;
	if (num < -2147483648 || num > 2147483647)
		return (1);
	*arg_n = num;
	return (0);
}

/// @brief checks for \t, \\n, \v, \f, \r or space
static int	ft_iswhitespace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
