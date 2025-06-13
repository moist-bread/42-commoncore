/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:57:03 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/13 14:53:53 by rduro-pe         ###   ########.fr       */
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
	print_philos(data);
	init_philo_forks(data);
	init_philo_threads(data);
	return (true);
}

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

	ft_printf_fd(1, YEL "\ninit philo forks\n\n" DEF);
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		pthread_mutex_init(&curr->f_left, NULL);
		printf("[%d] left fork given\n", curr->id);
		curr = curr->right;
	}
	pthread_mutex_init(&curr->f_left, NULL);
	printf("[%d] left fork given\n", curr->id);
}

void	init_philo_threads(t_ph_data *data)
{
	t_ph_indiv	*curr;

	ft_printf_fd(1, YEL "\ninit philo threads\n\n" DEF);
	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		printf("[%d] is being created\n", curr->id);
		pthread_create(&curr->thr, NULL, &routine_cycle, curr);
		curr = curr->right;
	}
	printf("[%d] is being created\n", curr->id);
	pthread_create(&curr->thr, NULL, &routine_cycle, curr);
}
