/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/11 18:20:29 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*make_stacks(int argc, char *argv[]);
void		print_stack(int *stack, int top_idx);
void		rb_do(t_stacks *stk);
int			int_check(char argv[]);
int			arg_counter(int argc, char **args);
void		sort_stack(t_stacks *stk);
void		self_sort(t_stacks *stk);
int			sort_check(t_stacks *stk);

int	main(int argc, char *argv[])
{
	t_stacks	*stk;
	char		**args;

	if (argc == 1)
		return (1); // "GIVE PROMPT BACK"
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	argc = arg_counter(argc, args);
	if (argc <= 1)
		return (1); // "GIVE PROMPT BACK"
	if (input_check(args))
		return (1);
	stk = make_stacks(argc, args);
	if (!stk)
		return (0);
	if (repeat_check(stk))
		return (1);
	print_both_stacks(stk);
	sort_stack(stk);
	print_both_stacks(stk);
	// ft_printf("(args)%i\n", argc);
	// ra_do(stk);
	// print_both_stacks(stk);
	// pb_do(stk);
	// pb_do(stk);
	// print_both_stacks(stk);
	// ss_do(stk);
	// print_both_stacks(stk);
	// pa_do(stk);
	// print_both_stacks(stk);
}

void	sort_stack(t_stacks *stk)
{
	(void)stk;
	if (stk->atop_id < 3)
		self_sort(stk);
}

void	self_sort(t_stacks *stk)
{
	if (!sort_check(stk))
	{
		if (stk->a[2] < stk->a[1]) // 2 3 1
			rra_do(stk);
		if (stk->a[2] > stk->a[1] && stk->a[2] > stk->a[0]) // 3 1 2
			ra_do(stk);
		if (stk->a[2] > stk->a[1] && stk->a[2] < stk->a[0]) // 2 1 3
			sa_do(stk);
		// ft_printf("entrou\n");
	}
	// 1 2 3	0
	// 1 3 2	2 rra (2 1 3) + sa
	// 2 3 1	1 rra
	// 2 1 3	1 sa
	// 3 2 1	2 ra (2 1 3) + sa
	// 3 1 2	1 ra
}

int	sort_check(t_stacks *stk)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stk->atop_id)
	{
		j = 0;
		while (++j + i <= stk->atop_id)
			if (stk->a[i] < stk->a[i + j])
				return (0);
	}
	return (1);
}

int	arg_counter(int argc, char **args)
{
	int	count;

	count = 0;
	if (argc == 1)
		return (1);
	if (argc > 2)
		return (--argc);
	while (args[count])
		count++;
	return (count);
}

t_stacks	*make_stacks(int argc, char *argv[])
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

void	free_stacks(t_stacks *stk)
{
	free(stk->a);
	free(stk->b);
	free(stk);
}

void	print_stack(int *stack, int top_idx)
{
	if (top_idx < 0)
		ft_printf("|empty| (%i)\n", top_idx);
	while (top_idx >= 0)
	{
		ft_printf("|%i| (%i)\n", stack[top_idx], top_idx);
		top_idx--;
	}
	ft_printf("\n");
}

void	print_both_stacks(t_stacks *stk)
{
	print_stack(stk->a, stk->atop_id);
	print_stack(stk->b, stk->btop_id);
}
