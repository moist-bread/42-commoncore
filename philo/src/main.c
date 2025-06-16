/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/16 19:04:03 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	safe_sleep(int t_sleep);

int	main(int ac, char **av)
{
	t_ph_data	ph_data;

	ft_printf_fd(1, YEL "PHILO MAIN ENTERED\n\n" DEF);
	ph_data = (t_ph_data){0};
	ph_data.t_start = -1;
	if (ac - 1 > 5 || ac - 1 < 4)
		return (ft_printf_fd(2, M_ARGAMT M_USAGE), 2);
	if (!validate_args(ac - 1, &av[1], &ph_data.val))
		return (2);
	if (!create_needed_philos(&ph_data))
		return (1);
	// while (1)
	// {
	// 	//lock
	// 	if (died || full)
	// 		break ;
	// 	//unlock
	// }
	join_all_philos(&ph_data);
	return (printf("\n~ the end ~\n"), 0);
}

void	*routine_cycle(void *philo)
{
	t_ph_indiv	*ph;
	int			i;

	ph = (t_ph_indiv *)philo;
	if (ph->val.n_phi == 1)
		return (printf("might aswell just die\n"), NULL);
	if (ph->id % 2 != 0)
		safe_sleep(ph->val.t_eat / 2);
	i = -1;
	while ((ph->val.n_eat && ++i < ph->val.n_eat) || (!ph->val.n_eat))
	{
		pthread_mutex_lock(&ph->fork_l);
		print_act(ph->data, ph->id, 'F');
		pthread_mutex_lock(&ph->right->fork_l);
		print_act(ph->data, ph->id, 'F');
		print_act(ph->data, ph->id, 'E');
		safe_sleep(ph->val.t_eat);
		pthread_mutex_unlock(&ph->fork_l);
		pthread_mutex_unlock(&ph->right->fork_l);
		ph->t_last_eat = get_curr_time();
		print_act(ph->data, ph->id, 'S');
		safe_sleep(ph->val.t_slp);
		if (get_curr_time() - ph->t_last_eat > ph->val.t_die)
		{
			print_act(ph->data, ph->id, 'D');
			pthread_mutex_lock(&ph->data->check_died);
			ph->data->died = true;
			pthread_mutex_unlock(&ph->data->check_died);
			return (NULL);
		}
		print_act(ph->data, ph->id, 'T');
		safe_sleep(ph->val.t_slp - ph->val.t_eat);
		if (get_curr_time() - ph->t_last_eat > ph->val.t_die)
		{
			print_act(ph->data, ph->id, 'D');
			pthread_mutex_lock(&ph->data->check_died);
			ph->data->died = true;
			pthread_mutex_unlock(&ph->data->check_died);
			return (NULL);
		}
	}
	return (NULL);
}

/// @brief
/// @param data
/// @param id
/// @param type 'F'- fork 'E'- eating 'S'- sleeping 'T'- thinking 'D'- died
void	print_act(t_ph_data *data, int id, char type)
{
	pthread_mutex_lock(&data->check_died);
	if (data->died)
	{
		pthread_mutex_unlock(&data->check_died);
		return ;
	}
	pthread_mutex_unlock(&data->check_died);
	pthread_mutex_lock(&data->print_t);
	if (type == 'F')
		printf("%ld\t[%d]\thas taken a fork\n", get_curr_time() - data->t_start,
			id);
	else if (type == 'E')
		printf("%ld\t[%d]\tis eating\n", get_curr_time() - data->t_start, id);
	else if (type == 'S')
		printf("%ld\t[%d]\tis sleeping\n", get_curr_time() - data->t_start, id);
	else if (type == 'T')
		printf("%ld\t[%d]\tis thinking\n", get_curr_time() - data->t_start, id);
	else if (type == 'D')
		printf("%ld\t[%d]\tdied\n", get_curr_time() - data->t_start, id);
	pthread_mutex_unlock(&data->print_t);
}

long	get_curr_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	safe_sleep(int t_sleep)
{
	long	t_start;
	long	elapsed_time;

	if (t_sleep <= 0)
		return ;
	t_start = get_curr_time();
	elapsed_time = 0;
	while (elapsed_time < t_sleep)
	{
		usleep(100);
		elapsed_time = get_curr_time() - t_start;
		// printf("[elapsed time]  millisec: %ld\n", elapsed_time);
	}
}
