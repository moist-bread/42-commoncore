/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:02:13 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/22 18:54:02 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief parses recieved arguments and validates them
/// @param ac amount of arguments
/// @param av the arguments
/// @param ph_dt pointer struct where to store parsed args
/// @return true when args are valid, false when not
bool	validate_args(int ac, char **av, t_ph_val *ph_val)
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
	while (++i < ac)
		if (value[i] <= 0 || (i == 0 && value[i] > 200))
			return (specify_arg_error(i), false);
	ph_val->n_phi = value[0];
	ph_val->t_die = value[1];
	ph_val->t_eat = value[2];
	ph_val->t_slp = value[3];
	ph_val->n_eat = value[4];
	return (true);
}

/// @brief writes an error message according to the invalid arg
/// @param idx index that idicates the invalid arg
void	specify_arg_error(int idx)
{
	if (idx == 0)
		ft_putstr_fd("invalid: " BLUB " number_of_philosophers " DEF \
			M_NBT200, 2);
	else if (idx == 1)
		ft_putstr_fd("invalid: " BBLK WHTB " time_to_die " DEF M_NBIG0, 2);
	else if (idx == 2)
		ft_putstr_fd("invalid: " YELB " time_to_eat " DEF M_NBIG0, 2);
	else if (idx == 3)
		ft_putstr_fd("invalid: " MAGB " time_to_sleep " DEF M_NBIG0, 2);
	else if (idx == 4)
		ft_putstr_fd("invalid: " GRNB \
			" number_of_times_each_philosopher_must_eat " DEF M_NBIG0, 2);
	ft_putstr_fd(M_USAGE, 2);
}
