/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/16 19:02:01 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// -->┊( LIBS )┊.´-★☆★
# include "libft/libft.h"
# include "philo_structs.h"
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// -->┊( DEFINES )┊.´-★☆★

//-‵,┊ colors
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define CYN "\e[0;36m"
# define DEF "\e[0m"

//-‵,┊ bg colors
# define YELB "\e[43m"

//-‵,┊ error messages
# define M_ARGAMT "incorrect amount of arguments provided\n"
# define M_USAGE \
	"\nusage: ./philo [number_of_philosophers] [time_to_die]\n\
[time_to_eat] [time_to_sleep] (number_of_times_each_philosopher_must_eat)\n"

// -->┊( TBD )┊.´-★☆★
void	*check_for_death(void *data);
long	get_curr_time(void);
void	print_act(t_ph_data *data, int id, char type);
bool	validate_args(int ac, char **av, t_ph_val *ph_dt);
void	specify_arg_error(int idx);

bool	create_needed_philos(t_ph_data *data);
bool	init_philo_list(t_ph_data *data, int id);
void	init_philo_forks(t_ph_data *data);
void	init_philo_threads(t_ph_data *data);

void	*routine_cycle(void *id);
void	print_philos(t_ph_data *data);

void	join_all_philos(t_ph_data *data);

#endif