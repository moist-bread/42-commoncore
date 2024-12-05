/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/05 20:42:52 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stacks	*make_stacks(int argc, char *argv[]);
void	print_stack(int *stack, int top_idx);
void	rb_do(stacks *stk);

int	main(int argc, char *argv[])
{
	stacks	*stk;

	if (argc < 3)
		return (0); // INSTEAD OF RETURN "GIVE PROMPT BACK"
	// ft_printf("%i\n", argc);
	// check if theyre all ints else write "Error"
	// check if there are duplicates
	if (input_checker(argc, argv))
		return (1);
	stk = make_stacks(argc, argv);
	if (!stk)
		return (0);
	print_both_stacks(stk);
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

int input_checker(int argc, char *argv[])
{
	int	error;
	int i;

	error = 0;
	i = 1;
	while (i < argc)
	{
		is_num(argv[i]);
		
		i++;
	}
		
	
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

is_num(char *argv[])
{
	int j;
	
	j = -1;
	while(*argv[++j])
	{
		if(*argv[0] == '-' || *argv[0] == '+')
			j++;
		if (*argv[j] < '0' && *argv[j] > '9')
		{
			error++;
			break;
		}
		
	}
	
}

stacks	*make_stacks(int argc, char *argv[])
{
	stacks	*stk;

	stk = malloc(sizeof(stacks));
	if (!stk)
		return (NULL);
	stk->a = malloc(--argc * sizeof(int));
	if (!stk->a)
		return (NULL);
	stk->b = malloc(argc * sizeof(int));
	if (!stk->b)
		return (NULL);
	stk->atop_id = -1;
	stk->btop_id = -1;
	while (++stk->atop_id < argc)
		stk->a[stk->atop_id] = ft_atoi(argv[argc - stk->atop_id]);
	stk->atop_id--;
	return (stk);
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

void	print_both_stacks(stacks *stk)
{
	print_stack(stk->a, stk->atop_id);
	print_stack(stk->b, stk->btop_id);
}
