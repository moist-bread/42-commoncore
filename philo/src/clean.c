/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:00:46 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/13 18:18:44 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	join_all_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;
	t_ph_indiv	*next;

	sleep (15);
	ft_printf_fd(1, YEL "\njoin threads and destroy mutexes\n\n" DEF);
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		next = curr->right;
		printf("-- next\n");
		pthread_join(curr->thr, NULL);
		printf("cleaning philo no. %d\n", curr->id);
		pthread_mutex_destroy(&curr->f_left);
		free(curr);
		curr = next;
	}
	printf("-- next\n");
	pthread_join(curr->thr, NULL);
	printf("cleaning philo no. %d\n", curr->id);
	pthread_mutex_destroy(&curr->f_left);
	free(curr);
}
