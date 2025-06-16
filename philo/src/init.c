/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:57:03 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/16 19:03:48 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	create_needed_philos(t_ph_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->val.n_phi)
	{
		if (!init_philo_list(data, id))
			return (false);
	}
	init_philo_forks(data);
	pthread_mutex_init(&data->print_t, NULL);
	pthread_mutex_init(&data->check_died, NULL);
	data->t_start = get_curr_time();
	init_philo_threads(data);
	// pthread_create(&data->death_checker, NULL, &routine_cycle, data);
	return (true);
}

// void *check_for_death(void *data)
// {
// 	t_ph_data *dt;
	
// 	dt = (t_ph_data *)data;
// 	while (1)
// 	{
// 		pthread_mutex_lock(&dt->check_died);
// 		if (dt->died == true)
// 		{
// 			ft_printf_fd(1, YEL "\nwomp womppp   --\n" DEF);

// 			break;
// 		}
// 		pthread_mutex_unlock(&dt->check_died);
// 	}
// 	join_all_philos(data);
// 	return (NULL);
// }

bool	init_philo_list(t_ph_data *data, int id)
{
	t_ph_indiv	*temp;
	t_ph_indiv	*philo;

	printf("creating philo no. %d\n", id);
	philo = ft_calloc(1, sizeof(t_ph_indiv));
	if (!philo)
		return (false);
	philo->id = id;
	philo->val = (t_ph_val){data->val.n_phi, data->val.t_die, data->val.t_eat,
		data->val.t_slp, data->val.n_eat};
	philo->data = data;
	if (!data->head)
		data->head = philo;
	else
	{
		temp = data->head;
		while (temp->right)
			temp = temp->right;
		temp->right = philo;
		philo->left = temp;
		if (id == data->val.n_phi)
		{
			philo->right = data->head;
			data->head->left = philo;
		}
	}
	return (true);
}

void	init_philo_forks(t_ph_data *data)
{
	t_ph_indiv	*curr;

	ft_printf_fd(1, YEL "\niniting philo forks   --\n" DEF);
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		pthread_mutex_init(&curr->fork_l, NULL);
		curr = curr->right;
	}
	pthread_mutex_init(&curr->fork_l, NULL);
}

void	init_philo_threads(t_ph_data *data)
{
	t_ph_indiv	*curr;

	ft_printf_fd(1, YEL "initing philo threads --\n\n" DEF);
	curr = data->head;
	while (curr->id != data->val.n_phi)
	{
		pthread_create(&curr->thr, NULL, &routine_cycle, curr);
		curr = curr->right;
	}
	pthread_create(&curr->thr, NULL, &routine_cycle, curr);
}
