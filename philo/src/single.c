/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:16 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/20 16:07:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*single_philo_cycle(t_ph_indiv *ph)
{
	print_act(ph->data, ph->id, 'F');
	if (!safe_sleep(ph->val.t_die, ph))
		return (pthread_mutex_unlock(&ph->data->end_lock), NULL);
	pthread_mutex_lock(&ph->data->death_lock);
	print_act(ph->data, ph->id, 'D');
	access_end_var(&ph->data->end_lock, &ph->data->end, 'C');
	pthread_mutex_unlock(&ph->data->death_lock);
	pthread_mutex_unlock(&ph->data->end_lock);
	return (NULL);
}
