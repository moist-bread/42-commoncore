/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/13 18:16:27 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void safe_sleep(int t_sleep);

int	main(int ac, char **av)
{
	t_ph_data		ph_data;
	
	ft_printf_fd(1, YEL "PHILO MAIN ENTERED\n\n" DEF);
	ph_data = (t_ph_data){0};
	// step 1: parse values --
	if (ac - 1 > 5 || ac - 1 < 4)
	return (ft_printf_fd(2, M_ARGAMT M_USAGE), 2);
	if (!validate_args(ac - 1, &av[1], &ph_data.val))
	return (2);
	// step 2: create and init structs --
	if (!create_needed_philos(&ph_data))
		return (1);
	join_all_philos(&ph_data);

	// safe_sleep(1000);
	
	// gettimeofday tests
	//
	// struct timeval	tv_s;
	// struct timeval	tv_e;
	// long			elapsed_time;
	// gettimeofday(&tv_s, NULL);
	// printf("[starting time] sec: %ld microsec: %ld\n", tv_s.tv_sec,
	// 	tv_s.tv_usec);
	// usleep(300000);
	// gettimeofday(&tv_e, NULL);
	// printf("[ending time]   sec: %ld microsec: %ld\n", tv_e.tv_sec,
	// 	tv_e.tv_usec);
	// printf("[difference]    sec: %ld          microsec: %ld\n", tv_e.tv_sec
	// 	- tv_s.tv_sec, tv_e.tv_usec - tv_s.tv_usec);
	// elapsed_time = (tv_e.tv_sec - tv_s.tv_sec) * 1000 + (tv_e.tv_usec
	// 		- tv_s.tv_usec) / 1000;
	// printf("\n[elapsed time]  millisec: %ld\n", elapsed_time);
	// pthread tests
	//
	// pthread_t phi;
	// pthread_create(&phi, NULL, &routine_cycle, NULL);
	// pthread_join(phi, NULL);
	return (printf("\n~ the end ~\n"), 0);
}

void	*routine_cycle(void *philo)
{
	t_ph_indiv	*ph;
	int i;

	ph = (t_ph_indiv *)philo;
	if (ph->val.n_phi == 1)
		return (printf("might aswell just die\n"), NULL);
	if (ph->id % 2 != 0)
		safe_sleep (ph->val.t_eat / 2);
	i = -1;
	while ((ph->val.n_eat && ++i < ph->val.n_eat) || (!ph->val.n_eat))
	{
		pthread_mutex_lock(&ph->f_left);
		pthread_mutex_lock(&ph->right->f_left);
		if (ph->id % 2 != 0)
			printf("i am [%d] and i am last whomp whomp\n", ph->id);
		else
			printf("i am [%d] and i am first haha!\n", ph->id);
		safe_sleep (ph->val.t_eat);
		pthread_mutex_unlock(&ph->f_left);
		pthread_mutex_unlock(&ph->right->f_left);
		safe_sleep (ph->val.t_slp);
	}
	return (NULL);
}

void safe_sleep(int t_sleep)
{
	struct timeval	tv_s;
	struct timeval	tv_e;
	long			t_start;
	long			elapsed_time;
	
	gettimeofday(&tv_s, NULL);
	// printf("[starting time] sec: %ld microsec: %ld\n", tv_s.tv_sec,
	// 	tv_s.tv_usec);
	t_start = (tv_s.tv_sec * 1000) + (tv_s.tv_usec / 1000);
	elapsed_time = 0;
	while (elapsed_time < t_sleep)
	{
		usleep(100);	
		gettimeofday(&tv_e, NULL);
		elapsed_time = (tv_e.tv_sec - tv_s.tv_sec) * 1000 + (tv_e.tv_usec
				- tv_s.tv_usec) / 1000;
		// printf("[elapsed time]  millisec: %ld\n", elapsed_time);
	}
}