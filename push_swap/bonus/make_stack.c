/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:14:37 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/28 17:15:03 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	arg_counter(int argc, char **args)
{
	int	count;

	count = 0;
	if (argc > 2)
		return (--argc);
	while (args[count])
		count++;
	return (count);
}

t_stacks	*make_stacks(int argc, char **argv)
{
	t_stacks	*stk;

	stk = malloc(sizeof(t_stacks));
	if (!stk)
		return (NULL);
	stk->a = malloc(argc * sizeof(int));
	if (!stk->a)
		return (NULL);
	stk->b = malloc(argc * sizeof(int));
	if (!stk->b)
		return (NULL);
	stk->atop_id = -1;
	stk->btop_id = -1;
	while (++stk->atop_id < argc)
		stk->a[stk->atop_id] = ft_atoi(argv[argc - stk->atop_id - 1]);
	stk->atop_id--;
	return (stk);
}

int	free_args(char **args, int argc, int spt)
{
	int	i;

	if (!spt)
		return (1);
	i = 0;
	while (i <= argc)
		free(args[i++]);
	free(args);
	return (1);
}

void	free_stacks(t_stacks *stk)
{
	free(stk->a);
	free(stk->b);
	free(stk);
}
