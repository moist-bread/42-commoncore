/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/22 17:49:39 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

// -‵,┊  main library
# include "philo.h"

// -->┊( STRUCTS )┊.´-★☆★

typedef struct s_ph_val
{
	int					n_phi;
	int					t_die;
	int					t_eat;
	int					t_slp;
	int					n_eat;
}						t_ph_val;

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

typedef struct s_ph_data
{
	t_ph_val			val;
	t_ph_indiv			*head;
	pthread_t			end_checker;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		end_lock;
	int					end;
	long				t_start;
	pthread_mutex_t		print_t;
}						t_ph_data;

#endif