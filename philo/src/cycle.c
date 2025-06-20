/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:00:46 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/20 15:54:30 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

bool	eating_act(t_ph_indiv *ph)
{
	if (access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
		return (false);
	pthread_mutex_lock(&ph->fork_l);
	if (!print_act(ph->data, ph->id, 'F'))
		return (printf("\nsaida no print 1\n"),
			pthread_mutex_unlock(&ph->fork_l), false);
	pthread_mutex_lock(&ph->right->fork_l);
	if (!print_act(ph->data, ph->id, 'F'))
		return (printf("\nsaida no print 2\n"),
			pthread_mutex_unlock(&ph->fork_l),
			pthread_mutex_unlock(&ph->right->fork_l), false);
	if (!print_act(ph->data, ph->id, 'E'))
		return (printf("\nsaida no print 3\n"),
			pthread_mutex_unlock(&ph->fork_l),
			pthread_mutex_unlock(&ph->right->fork_l), false);
	if (!safe_sleep(ph->val.t_eat, ph))
		return (pthread_mutex_unlock(&ph->fork_l),
			pthread_mutex_unlock(&ph->right->fork_l), false);
	pthread_mutex_unlock(&ph->fork_l);
	pthread_mutex_unlock(&ph->right->fork_l);
	ph->t_last_eat = get_curr_time();
	return (true);
}

bool	philos_are_full(t_ph_indiv *ph, int idx)
{
	if (ph->val.n_eat && idx == ph->val.n_eat - 1 && ((ph->val.n_phi % 2 != 0
				&& ph->id == ph->val.n_phi) || (ph->val.n_phi % 2 == 0
				&& ph->id == ph->val.n_phi - 1)))
	{
		print_act(ph->data, ph->id, 'M');
		access_end_var(&ph->data->end_lock, &ph->data->end, 'C');
		return (true);
	}
	return (false);
}

bool	sleeping_act(t_ph_indiv *ph)
{
	if (!print_act(ph->data, ph->id, 'S'))
		return (printf("\nsaida no print 4\n"), false);
	if (!safe_sleep(ph->val.t_slp, ph))
		return (false);
	else
		return (true);
}

bool	thinking_act(t_ph_indiv *ph)
{
	int	t_think;

	if (!print_act(ph->data, ph->id, 'T'))
		return (printf("\nsaida no print 5\n"), false);
	if (ph->val.t_eat <= ph->val.t_slp)
		t_think = 0;
	else
		t_think = ph->val.t_slp - ph->val.t_eat;
	if (!safe_sleep(t_think, ph))
		return (false);
	else
		return (true);
}
