/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:02:13 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/12 12:30:45 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	validate_args(int ac, char **av, t_ph_val *ph_dt)
{
	int	i;
	int	value[5];

	ft_bzero(value, sizeof(value));
	i = -1;
	while (av[++i])
	{
		if (!int_check(av[i], &value[i]))
			return (specify_arg_error(i), false);
	}
	i = -1;
	printf("pre verification values:\n\n");
	while (++i < ac)
		printf("%d\t", value[i]);
	printf("\n\n");
	i = -1;
	while (++i < ac)
		if (value[i] <= 0 || (i == 0 && value[i] > 200))
			return (specify_arg_error(i), false);
	ph_dt->n_phi = value[0];
	ph_dt->t_die = value[1];
	ph_dt->t_eat = value[2];
	ph_dt->t_slp = value[3];
	ph_dt->n_eat = value[4];
	return (true);
}

void	specify_arg_error(int idx)
{
	if (idx == 0)
		ft_printf_fd(2, "invalid number_of_philosophers, \
	only numeric values between 0-200 permitted\n");
	else if (idx == 1)
		ft_printf_fd(2, "invalid time_to_die,\
	only numeric values bigger than 0 permitted\n");
	else if (idx == 2)
		ft_printf_fd(2, "invalid time_to_eat,\
	only numeric values bigger than 0 permitted\n");
	else if (idx == 3)
		ft_printf_fd(2, "invalid time_to_sleep,\
	only numeric values bigger than 0 permitted\n");
	else if (idx == 4)
		ft_printf_fd(2, "invalid number_of_times_each_philosopher_must_eat,\
	only numeric values bigger than 0 permitted\n");
	ft_printf_fd(2, M_USAGE);
}
