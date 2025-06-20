/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:57:03 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/20 18:03:03 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	create_needed_philos(t_ph_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->val.n_phi)
	{
		if (!init_philo_list(data, id))
			return (ft_printf_fd(2, "malloc: " M_INITFAIL), false);
	}
	init_philo_forks(data);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->end_lock, NULL);
	pthread_mutex_init(&data->print_t, NULL);
	data->t_start = get_curr_time();
	init_philo_threads(data);
	return (true);
}

bool	init_philo_list(t_ph_data *data, int id)
{
	t_ph_indiv	*temp;
	t_ph_indiv	*philo;

	philo = ft_calloc(1, sizeof(t_ph_indiv));
	if (!philo)
		return (free_philo_list(data), false);
	philo->id = id;
	philo->val = data->val;
	philo->data = data;
	if (!data->head)
		data->head = philo;
	else
	{
		temp = data->head;
		while (temp->right)
			temp = temp->right;
		temp->right = philo;
		philo->left = temp;
		if (id == data->val.n_phi)
		{
			philo->right = data->head;
			data->head->left = philo;
		}
	}
	return (true);
}

void	init_philo_forks(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		pthread_mutex_init(&curr->fork_l, NULL);
		curr = curr->right;
	}
	pthread_mutex_init(&curr->fork_l, NULL);
}

bool	init_philo_threads(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	while (curr->id != data->val.n_phi)
	{
		if (pthread_create(&curr->thr, NULL, &routine_cycle, curr) != 0)
		{
			pthread_mutex_lock(&data->print_t);
			access_end_var(&data->end_lock, &data->end, 'C');
			ft_printf_fd(2, "pthread_create: " M_INITFAIL);
			pthread_mutex_unlock(&data->end_lock);
			pthread_mutex_unlock(&data->print_t);
		}
		curr = curr->right;
	}
	if (pthread_create(&curr->thr, NULL, &routine_cycle, curr) != 0)
	{
		pthread_mutex_lock(&data->print_t);
		access_end_var(&data->end_lock, &data->end, 'C');
		ft_printf_fd(2, "pthread_create: " M_INITFAIL);
		pthread_mutex_unlock(&data->end_lock);
		pthread_mutex_unlock(&data->print_t);
		return (false);
	}
	return (true);
}
