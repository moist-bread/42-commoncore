/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:00:46 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/18 18:31:59 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine_cycle(void *philo)
{
	t_ph_indiv	*ph;
	int			i;

	ph = (t_ph_indiv *)philo;
	if (ph->val.n_phi == 1)
		return (printf("might aswell just die\n"), NULL);
	ph->t_last_eat = get_curr_time();
	if (ph->id % 2 != 0)
		safe_sleep(ph->val.t_eat / 2, ph);
	i = -1;
	while (((ph->val.n_eat && ++i <= ph->val.n_eat) || !ph->val.n_eat) && !access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
	{
		// if (access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
		// 	return (NULL);
		pthread_mutex_lock(&ph->fork_l);
		print_act(ph->data, ph->id, 'F');
		pthread_mutex_lock(&ph->right->fork_l);
		print_act(ph->data, ph->id, 'F');
		print_act(ph->data, ph->id, 'E');
		if (!safe_sleep(ph->val.t_eat, ph))
			return (pthread_mutex_unlock(&ph->fork_l),
				pthread_mutex_unlock(&ph->right->fork_l), NULL);
		pthread_mutex_unlock(&ph->fork_l);
		pthread_mutex_unlock(&ph->right->fork_l);
		ph->t_last_eat = get_curr_time();
		if (ph->val.n_eat && i == ph->val.n_eat - 1
			&& is_last_philo(ph->val.n_phi, ph->id))
			return (print_act(ph->data, ph->id, 'M'),
				access_end_var(&ph->data->end_lock, &ph->data->end, 'C'), NULL);
		print_act(ph->data, ph->id, 'S');
		if (!safe_sleep(ph->val.t_slp, ph))
			return (NULL);
		if (!thinking_act(ph))
			return (NULL);
	}
	return (NULL);
}

bool	thinking_act(t_ph_indiv *ph)
{
	int	t_think;

	if (access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
			return (printf("\nexit in THINK\n") ,false);
	print_act(ph->data, ph->id, 'T');
	if (ph->val.t_eat <= ph->val.t_slp)
		t_think = 0;
	else
		t_think = ph->val.t_slp - ph->val.t_eat;
	if (!safe_sleep(t_think, ph))
		return (false);
	else
		return (true);
}

void	*checker_cycle(void *data)
{
	t_ph_data	*dt;

	dt = (t_ph_data *)data;
	while (1)
	{
		usleep(1000);
		if (access_end_var(&dt->end_lock, &dt->end, 'V') == true)
			break ;
	}
	join_all_philos(data);
	return (NULL);
}
