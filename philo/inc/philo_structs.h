/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/11 18:46:21 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

// -‵,┊  main library
# include "philo.h"

// -->┊( STRUCTS )┊.´-★☆★

typedef struct s_philo_data
{
	int		n_phi;
	int		t_die;
	int		t_eat;
	int		t_slp;
	int		n_eat;
}			t_philo_data;

#endif