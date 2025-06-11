/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/11 19:03:00 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	ft_printf_fd(1, YEL "PHILO MAIN ENTERED\n\n" DEF);
	
	t_philo_data ph_dt;
	
	ph_dt = (t_philo_data){0};
	// step 1: parse values --
	if (ac - 1 > 5 || ac - 1 < 4)
		return (ft_printf_fd(2, M_ARGAMT M_USAGE), 2);
	if (!validate_args(ac - 1, &av[1], &ph_dt))
		return (2);
	
	// step 2: problema pra raquel do futuro --
	
	// gettimeofday tests
	//
	// struct timeval tv_s;
	// struct timeval tv_e;
	// long					elapsed_time;
	// gettimeofday(&tv_s, NULL);
	// printf("[starting time] sec: %ld microsec: %ld\n", tv_s.tv_sec, tv_s.tv_usec);
	// usleep(300000);
	// gettimeofday(&tv_e, NULL);
	// printf("[ending time]   sec: %ld microsec: %ld\n", tv_e.tv_sec, tv_e.tv_usec);
	// printf("[difference]    sec: %ld          microsec: %ld\n", tv_e.tv_sec - tv_s.tv_sec, tv_e.tv_usec - tv_s.tv_usec);
	// elapsed_time = (tv_e.tv_sec - tv_s.tv_sec) * 1000 + (tv_e.tv_usec - tv_s.tv_usec) / 1000;
	// printf("\n[elapsed time]  millisec: %ld\n", elapsed_time);
	
	
	// pthread tests
	//
	// pthread_t phi;
	// pthread_create(&phi, NULL, &routine_cycle, NULL);
	// pthread_join(phi, NULL);
	
	return (0);
}

void	*routine_cycle()
{
	printf("i am a thread and im digging a hole\n");
	return (NULL);
}