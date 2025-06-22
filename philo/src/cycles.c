/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:00:46 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/22 17:57:56 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief philosopher's simulation cycle of eating, sleeping and thinking
/// @param philo data of the philo doing the cycle
void	*routine_cycle(void *philo)
{
	t_ph_indiv	*ph;
	int			i;

	ph = (t_ph_indiv *)philo;
	ph->t_last_eat = get_curr_time();
	if (ph->val.n_phi == 1)
		return (single_philo_cycle(ph));
	if (ph->id % 2 != 0)
		if (!safe_sleep(ph->val.t_eat / 2, ph))
			return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
	i = -1;
	while ((ph->val.n_eat && ++i <= ph->val.n_eat) || !ph->val.n_eat)
	{
		if (!eating_act(ph))
			return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
		if (philos_are_full(ph, i))
			return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
		if (!sleeping_act(ph))
			return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
		if (!thinking_act(ph))
			return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
	}
	return (NULL);
}

/// @brief cycle for a single philosopher predicted to die
/// @param ph data of the philo doing the cycle
void	*single_philo_cycle(t_ph_indiv *ph)
{
	print_act(ph->data, ph->id, 'F');
	if (!safe_sleep(ph->val.t_die, ph))
		return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
	print_act(ph->data, ph->id, 'D');
	access_end_var(&ph->data->end_lock, &ph->data->end, 'C');
	pthread_mutex_unlock(&ph->data->end_lock);
	return (NULL);
}

/// @brief cycle for the thread that checks if the simulation has finished
/// @param data stores all simulation data
void	*checker_cycle(void *data)
{
	t_ph_data	*dt;

	dt = (t_ph_data *)data;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&dt->end_lock);
		if (dt->end == dt->val.n_phi)
		{
			pthread_mutex_unlock(&dt->end_lock);
			break ;
		}
		pthread_mutex_unlock(&dt->end_lock);
	}
	clean_philos(data);
	return (NULL);
}
