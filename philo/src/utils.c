/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:40:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/18 18:22:04 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_curr_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

bool	safe_sleep(int t_sleep, t_ph_indiv *ph)
{
	long	t_start;
	long	curr_time;
	long	elapsed_time;

	if (t_sleep <= 0)
		return (true);
	t_start = get_curr_time();
	elapsed_time = 0;
	while (elapsed_time < t_sleep)
	{
		usleep(100);
		curr_time = get_curr_time();
		elapsed_time = curr_time - t_start;
		if (access_end_var(&ph->data->end_lock, &ph->data->end, 'V'))
			return (printf("\nSAIDA NO SLEEP\n") ,false);
		if (curr_time - ph->t_last_eat > ph->val.t_die)
		{
			pthread_mutex_lock(&ph->data->sleep_death);
			print_act(ph->data, ph->id, 'D');
			access_end_var(&ph->data->end_lock, &ph->data->end, 'C');
			pthread_mutex_unlock(&ph->data->sleep_death);
			return (false);
		}
	}
	return (true);
}

/// @brief
/// @param data
/// @param id
/// @param type 'F'- fork 'E'- eating 'S'- sleeping 'T'- thinking 'D'- died 'M'- must eat full
void	print_act(t_ph_data *data, int id, char type)
{
	long	time;

	if (access_end_var(&data->end_lock, &data->end, 'V'))
		return ;
	pthread_mutex_lock(&data->print_t);
	time = get_curr_time() - data->t_start;
	if (time < 100)
		printf(" ⏰  %ld\t\t" BBLU "【" DEF " ", time);
	else
		printf(" ⏰  %ld\t" BBLU "【" DEF " ", time);
	if (type == 'F')
		printf("%d\t" BBLU "】" DEF BLUB "Ξ  has taken a fork  Ξ" DEF "\n", id);
	else if (type == 'E')
		printf("%d\t" BBLU "】" DEF YELB "Ξ  is eating         Ξ" DEF "\n", id);
	else if (type == 'S')
		printf("%d\t" BBLU "】" DEF MAGB "Ξ  is sleeping       Ξ" DEF "\n", id);
	else if (type == 'T')
		printf("%d\t" BBLU "】" DEF CYNB "Ξ  is thinking       Ξ" DEF "\n", id);
	else if (type == 'D')
		printf("%d\t" BBLU "】" BBLK WHTB "Ξ  died              Ξ" DEF "\n", id);
	else if (type == 'M')
		printf(":)\t" BBLU "】" DEF GRNB "Ξ  philos are full   Ξ" DEF "\n");
	pthread_mutex_unlock(&data->print_t);
}

bool	is_last_philo(int total_philos, int philo_id)
{
	if (total_philos % 2 != 0 && philo_id == total_philos)
		return (true);
	else if (total_philos % 2 == 0 && philo_id == total_philos - 1)
		return (true);
	return (false);
}

bool	access_end_var(pthread_mutex_t *end_lock, bool *end, char type)
{
	pthread_mutex_lock(end_lock);
	if (type == 'V' && *end == true)
	{
		pthread_mutex_unlock(end_lock);
		return (true);
	}
	else if (type == 'C')
		*end = true;
	pthread_mutex_unlock(end_lock);
	return (false);
}
