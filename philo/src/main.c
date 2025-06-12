/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/12 18:49:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	create_needed_philos(t_ph_data *data);
bool	init_and_create_philos(t_ph_data *data, int id);
void	*routine_cycle(void *id);
void	join_all_philos(t_ph_data *data);
void	print_philos(t_ph_data *data);

int	main(int ac, char **av)
{
	ft_printf_fd(1, YEL "PHILO MAIN ENTERED\n\n" DEF);
	
	t_ph_data ph_data;
	ph_data = (t_ph_data){0};
	
	// step 1: parse values --
	if (ac - 1 > 5 || ac - 1 < 4)
		return (ft_printf_fd(2, M_ARGAMT M_USAGE), 2);
	if (!validate_args(ac - 1, &av[1], &ph_data.val))
		return (2);
	if (!create_needed_philos(&ph_data))
		return (1);
	// print_philos(&ph_data);
	printf("huh???\n");
	// join_all_philos(&ph_data);
	// copy vals to new philo
	// t_ph_val new_ph_val;
	// new_ph_val = (t_ph_val){ph_val.n_phi, ph_val.t_die, ph_val.t_eat, ph_val.t_slp, ph_val.n_eat};
	
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

void print_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	ft_printf_fd(1, YEL "print philos %d\n\n" DEF, curr->id);
	// while (curr && curr->id != data.val.n_phi)
	// {
	// 	printf("hi my name is %d and im a node\n", curr->id);
	// 	curr = curr->right;
	// }
}

void join_all_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	while (curr && curr->id != data->val.n_phi)
	{
		printf("joining philo no. %d\n", curr->id);
		pthread_join(curr->thr, NULL);
		curr = curr->right;
	}
}

bool	create_needed_philos(t_ph_data *data)
{
	int id;
	
	id = 0;
	while (++id <= data->val.n_phi)
	{
		printf("creation loop\n");
		if (!init_and_create_philos(data, id))
			return (false);
		printf("\n");
	}
	return (true);
}

bool	init_and_create_philos(t_ph_data *data, int id)
{
	t_ph_indiv	*temp;
	t_ph_indiv	*philo;
	pthread_t phi_thr;

	phi_thr = 0;
	philo = ft_calloc(1, sizeof(t_ph_indiv));
	philo->id = id;
	// philo = &(t_ph_indiv){id, phi_thr, (t_ph_val){data->val.n_phi, \
	// 	data->val.t_die, data->val.t_eat, data->val.t_slp, data->val.n_eat}, NULL, NULL};
	printf("creating philo no. %d\n", philo->id);
	if (!data->head)
	{
		printf("first node\n");	
		data->head = philo;
	}
	else
	{
		printf("standard node\n");
		temp = data->head;
		while (temp->right)
			temp = temp->right;
		temp->right = philo;
		philo->left = temp;
		if (id == data->val.n_phi)
		{
			printf("last node\n");
			philo->right = data->head;
			data->head->left = philo;
		}
	}
	print_philos(data);
	return (true);
}


void	*routine_cycle(void *philo)
{
	// (void)philo;
	// printf("i am a  thread and im digging a hole\n");
	printf("i am a %d thread and im digging a hole\n", ((t_ph_indiv *)philo)->id );
	return (NULL);
}