/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/20 17:28:01 by rduro-pe         ###   ########.fr       */
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

# define DEF "\e[0m"

// ★☆★ regular text

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

// ★☆★ regular underline text

# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

// ★☆★ regular bold text

# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

// ★☆★ high intensty text

# define HBLK "\e[0;90m"
# define HRED "\e[0;91m"
# define HGRN "\e[0;92m"
# define HYEL "\e[0;93m"
# define HBLU "\e[0;94m"
# define HMAG "\e[0;95m"
# define HCYN "\e[0;96m"
# define HWHT "\e[0;97m"

// ★☆★ bold high intensity text

# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//-‵,┊ bg colors

// ★☆★ regular background

# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

// ★☆★ high intensty background

# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//-‵,┊ error messages

# define M_ARGAMT "incorrect amount of arguments provided\n"
# define M_USAGE \
"\nusage: ./philo [number_of_philosophers] [time_to_die]\n\
[time_to_eat] [time_to_sleep] (number_of_times_each_philosopher_must_eat)\n"
# define M_INITFAIL "failure in initialization\n"

// -->┊( TBD )┊.´-★☆★

void	free_philo_list(t_ph_data *data);

// cycles

void	*routine_cycle(void *id);
bool	eating_act(t_ph_indiv *ph);
bool	philos_are_full(t_ph_indiv *ph, int idx);
bool	sleeping_act(t_ph_indiv *ph);
bool	thinking_act(t_ph_indiv *ph);

// single

void	*single_philo_cycle(t_ph_indiv *ph);

// checker

void	*checker_cycle(void *data);
void	clean_philos(t_ph_data *data);

// utils

long	get_curr_time(void);
bool	safe_sleep(int t_sleep, t_ph_indiv *ph);
bool	access_end_var(pthread_mutex_t *end_lock, int *end, char type);
bool	print_act(t_ph_data *data, int id, char type);

// parse

bool	validate_args(int ac, char **av, t_ph_val *ph_dt);
void	specify_arg_error(int idx);

// init

bool	create_needed_philos(t_ph_data *data);
bool	init_philo_list(t_ph_data *data, int id);
void	init_philo_forks(t_ph_data *data);
bool	init_philo_threads(t_ph_data *data);

#endif