/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:20:40 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/20 17:45:34 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

void	clean_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;
	t_ph_indiv	*next;

	ft_printf("\njoin threads and destroy mutexes\n\n");
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		// printf("next --\n");
		next = curr->right;
		if (curr->thr)
			pthread_join(curr->thr, NULL);
		// printf("cleaning philo no. %d\n", curr->id);
		pthread_mutex_destroy(&curr->fork_l);
		free(curr);
		curr = next;
	}
	// printf("next --\n");
	if (curr->thr)
		pthread_join(curr->thr, NULL);
	// printf("cleaning philo no. %d\n", curr->id);
	pthread_mutex_destroy(&curr->fork_l);
	free(curr);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->end_lock);
	pthread_mutex_destroy(&data->print_t);
}

void	free_philo_list(t_ph_data *data)
{
	t_ph_indiv	*curr;
	t_ph_indiv	*next;

	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		next = curr->right;
		free(curr);
		curr = next;
	}
	free(curr);
}
