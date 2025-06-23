/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/23 17:01:22 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

// -‵,┊  main library
# include "philo.h"

// -->┊( STRUCTS )┊.´-★☆★

/// @brief parsed values for simulation
/// @param n_phi number of philosophers
/// @param t_die time to die
/// @param t_eat time to eat
/// @param t_slp time to sleep
/// @param n_eat num of times one must eat
typedef struct s_ph_val
{
	int					n_phi;
	int					t_die;
	int					t_eat;
	int					t_slp;
	int					n_eat;
}						t_ph_val;

/// @brief individual philosopher info
/// @param id number
/// @param thr thread
/// @param val values
/// @param fork mutex
/// @param t_last_eat time of last meal
/// @param data table data
/// @param right philo on the right
typedef struct s_ph_indiv
{
	int					id;
	pthread_t			thr;
	t_ph_val			val;
	pthread_mutex_t		fork;
	long				t_last_eat;
	struct s_ph_data	*data;
	struct s_ph_indiv	*right;
}						t_ph_indiv;

/// @brief overarching table data
/// @param val values
/// @param head linked list with all philos
/// @param end_checker checker thread
/// @param death_lock mutex
/// @param end_lock mutex
/// @param end n philos who've ended
/// @param full_lock mutex
/// @param full n philos who're full
/// @param print_t mutex
/// @param t_start sim start time
typedef struct s_ph_data
{
	t_ph_val			val;
	t_ph_indiv			*head;
	pthread_t			end_checker;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		end_lock;
	int					end;
	pthread_mutex_t		full_lock;
	int					full;
	pthread_mutex_t		print_t;
	long				t_start;
}						t_ph_data;

#endif