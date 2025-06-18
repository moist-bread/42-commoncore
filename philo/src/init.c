/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:57:03 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/18 18:14:08 by rduro-pe         ###   ########.fr       */
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
			return (false);
	}
	init_philo_forks(data);
	pthread_mutex_init(&data->sleep_death, NULL);
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

	printf("creating philo no. %d\n", id);
	philo = ft_calloc(1, sizeof(t_ph_indiv));
	if (!philo)
		return (false);
	philo->id = id;
	philo->val = (t_ph_val){data->val.n_phi, data->val.t_die, data->val.t_eat,
		data->val.t_slp, data->val.n_eat};
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

void	init_philo_threads(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	while (curr->id != data->val.n_phi)
	{
		pthread_create(&curr->thr, NULL, &routine_cycle, curr);
		curr = curr->right;
	}
	pthread_create(&curr->thr, NULL, &routine_cycle, curr);
}

void	join_all_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;
	t_ph_indiv	*next;

	ft_printf("\njoin threads and destroy mutexes\n\n");
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		// printf("next --\n");
		next = curr->right;
		pthread_join(curr->thr, NULL);
		// printf("cleaning philo no. %d\n", curr->id);
		pthread_mutex_destroy(&curr->fork_l);
		free(curr);
		curr = next;
	}
	// printf("next --\n");
	pthread_join(curr->thr, NULL);
	// printf("cleaning philo no. %d\n", curr->id);
	pthread_mutex_destroy(&curr->fork_l);
	free(curr);
	pthread_mutex_destroy(&data->sleep_death);
	pthread_mutex_destroy(&data->end_lock);
	pthread_mutex_destroy(&data->print_t);
}
