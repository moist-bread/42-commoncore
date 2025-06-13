/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:40:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/06/13 16:41:14 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_philos(t_ph_data *data)
{
	t_ph_indiv	*curr;

	curr = data->head;
	ft_printf_fd(1, YEL "\nprint philos\n\n" DEF);
	while (curr && curr->id != data->val.n_phi)
	{
		printf("hi my name is [%d] and im a philo\n", curr->id);
		curr = curr->right;
	}
	printf("hi my name is [%d] and im a philo\n", curr->id);
}
