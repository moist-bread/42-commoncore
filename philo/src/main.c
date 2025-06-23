/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/23 14:15:35 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_ph_data	ph_data;

	ph_data = (t_ph_data){0};
	if (ac - 1 > 5 || ac - 1 < 4)
		return (ft_putstr_fd(M_ARGAMT M_USAGE, 2), 2);
	if (!validate_args(ac - 1, &av[1], &ph_data.val))
		return (2);
	printf("\n " YELB M_GREET DEF "\n\n\n");
	if (!create_needed_philos(&ph_data))
		return (1);
	if (pthread_create(&ph_data.end_checker, NULL, &checker_cycle,
			&ph_data) != 0)
	{
		pthread_mutex_lock(&ph_data.print_t);
		ft_putstr_fd("pthread_create: " M_INITFAIL, 2);
		pthread_mutex_unlock(&ph_data.print_t);
		checker_cycle(&ph_data);
	}
	if (ph_data.end_checker)
		pthread_join(ph_data.end_checker, NULL);
	return (printf("\n\n\n\t" BLUB M_BYE DEF "\n\n"), 0);
}
