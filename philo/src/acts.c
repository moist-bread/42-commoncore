/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:43:52 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/23 17:52:46 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool	locking_and_eating(t_ph_indiv *ph, pthread_mutex_t *first_fork,
				pthread_mutex_t *second_fork);

bool	eating_act(t_ph_indiv *ph)
{
	if (access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
		return (false);
	if (ph->id % 2 != 0)
	{
		if (!locking_and_eating(ph, &ph->fork, &ph->right->fork))
			return (false);
	}
	else
	{
		if (!locking_and_eating(ph, &ph->right->fork, &ph->fork))
			return (false);
	}
	return (true);
}

static bool	locking_and_eating(t_ph_indiv *ph, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	if (!print_act(ph->data, ph->id, 'F'))
		return (pthread_mutex_unlock(first_fork), false);
	pthread_mutex_lock(second_fork);
	if (!print_act(ph->data, ph->id, 'F'))
		return (pthread_mutex_unlock(first_fork),
			pthread_mutex_unlock(second_fork), false);
	if (!print_act(ph->data, ph->id, 'E'))
		return (pthread_mutex_unlock(first_fork),
			pthread_mutex_unlock(second_fork), false);
	ph->t_last_eat = get_curr_time();
	if (!safe_sleep(ph->val.t_eat, ph))
		return (pthread_mutex_unlock(first_fork),
			pthread_mutex_unlock(second_fork), false);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
	return (true);
}

/// @brief only needed when must_eat arg is recieved
/// @param ph current philo
/// @param idx number of the current "meal"
/// @return true when all PH have eanten must_eat amount
bool	philos_are_full(t_ph_indiv *ph, int idx)
{
	if (ph->val.n_eat && idx == ph->val.n_eat)
	{
		pthread_mutex_lock(&ph->data->full_lock);
		ph->data->full++;
		if (ph->data->full == ph->val.n_phi)
		{
			print_act(ph->data, ph->id, 'M');
			access_end_var(&ph->data->end_lock, &ph->data->end, 'C');
			pthread_mutex_unlock(&ph->data->print_t);
			return (pthread_mutex_unlock(&ph->data->full_lock), true);
		}
		pthread_mutex_unlock(&ph->data->full_lock);
	}
	return (false);
}

bool	sleeping_act(t_ph_indiv *ph)
{
	if (!print_act(ph->data, ph->id, 'S'))
		return (false);
	if (!safe_sleep(ph->val.t_slp, ph))
		return (false);
	else
		return (true);
}

bool	thinking_act(t_ph_indiv *ph)
{
	int	t_think;

	if (!print_act(ph->data, ph->id, 'T'))
		return (false);
	if (ph->val.n_phi % 2 != 0)
		t_think = (2 * ph->val.t_eat) - ph->val.t_slp;
	else
		t_think = ph->val.t_eat - ph->val.t_slp;
	if (!safe_sleep(t_think, ph))
		return (false);
	else
		return (true);
}
