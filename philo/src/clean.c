/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:20:40 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/23 16:44:07 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief cleans all philosopher data
void	clean_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;
	t_ph_indiv	*next;

	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		next = curr->right;
		if (curr->thr)
			pthread_join(curr->thr, NULL);
		pthread_mutex_destroy(&curr->fork);
		free(curr);
		curr = next;
	}
	if (curr->thr)
		pthread_join(curr->thr, NULL);
	pthread_mutex_destroy(&curr->fork);
	free(curr);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->end_lock);
	pthread_mutex_destroy(&data->full_lock);
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
