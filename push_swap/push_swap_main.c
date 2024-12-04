/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/04 19:39:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stacks	*make_stacks(int argc, char *argv[]);
int		print_stack(int *stack, int len);
void	rb_do(stacks *stk);

int	main(int argc, char *argv[])
{
	stacks	*stk;

	stk = make_stacks(argc, argv);
	if (!stk)
		return (0);
	print_stack(stk->a, stk->atop_id);
	print_stack(stk->b, stk->btop_id);
	ra_do(stk);
	print_stack(stk->a, stk->atop_id);
	print_stack(stk->b, stk->btop_id);
	// pb_do(stk);
	// pb_do(stk);
	// print_stack(stk->a, stk->atop_id);
	// print_stack(stk->b, stk->btop_id);
	// ss_do(stk);
	// print_stack(stk->a, stk->atop_id);
	// print_stack(stk->b, stk->btop_id);
	// pa_do(stk);
	// print_stack(stk->a, stk->atop_id);
	// print_stack(stk->b, stk->btop_id);
}

stacks	*make_stacks(int argc, char *argv[])
{
	stacks	*stk;
	int		i;

	// ft_printf("%i\n", argc);
	if (argc < 3)
		return (NULL);
	// INSTEAD OF RETURN "GIVE PROMPT BACK"
	// check if theyre all ints else write "Error"
	// check if there are duplicates
	stk = malloc(sizeof(stacks));
	if (!stk)
		return (NULL);
	stk->a = malloc((argc - 1) * sizeof(int));
	if (!stk->a)
		return (NULL);
	stk->b = malloc((argc - 1) * sizeof(int));
	if (!stk->b)
		return (NULL);
	// ft_printf("BAD%i\n", argc);
	stk->atop_id = argc - 2;
	stk->btop_id = -1;
	i = 0;
	while (i <= stk->atop_id)
	{
		stk->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stk);
}

int	print_stack(int *stack, int top_idx)
{
	if (top_idx < 0)
		ft_printf("|empty| (%i)\n", top_idx);
	while (top_idx >= 0)
	{
		ft_printf("|%i| (%i)\n", stack[top_idx], top_idx);
		top_idx--;
	}
	ft_printf("\n");
	return (0);
}

void	sa_do(stacks *stk)
{
	int temp;
	
	if (stk->atop_id > 0)
	{
		temp = stk->a[stk->atop_id];
		stk->a[stk->atop_id] = stk->a[stk->atop_id - 1];
		stk->a[stk->atop_id - 1] = temp;
	}
}
void	sb_do(stacks *stk)
{
	int temp;
	
	if (stk->btop_id > 0)
	{
		temp = stk->b[stk->btop_id];
		stk->b[stk->btop_id] = stk->b[stk->btop_id - 1];
		stk->b[stk->btop_id - 1] = temp;
	}
}

void	ss_do(stacks *stk)
{
	sa_do(stk);
	sb_do(stk);
}

void	pa_do(stacks *stk)
{
	if (stk->btop_id >= 0)
	{
		stk->atop_id++;
		stk->a[stk->atop_id] = stk->b[stk->btop_id];
		stk->b[stk->btop_id] = 0;
		stk->btop_id--;
	}
}

void	pb_do(stacks *stk)
{
	if (stk->atop_id >= 0)
	{
		stk->btop_id++;
		stk->b[stk->btop_id] = stk->a[stk->atop_id];
		stk->a[stk->atop_id] = 0;
		stk->atop_id--;
	}
}

void	ra_do(stacks *stk)
{
	int temp;
	int i;
	
	if (stk->atop_id > 0)
	{
		i = stk->atop_id;
		temp = stk->a[stk->atop_id];
		while(i > 0)
		{
			stk->a[i] = stk->a[i - 1];
			i--;	
		}
		stk->a[i] = temp;
	}
}

void	rb_do(stacks *stk)
{
	int temp;
	int i;
	
	if (stk->btop_id > 0)
	{
		i = stk->btop_id;
		temp = stk->b[stk->btop_id];
		while(i > 0)
		{
			stk->b[i] = stk->b[i - 1];
			i--;	
		}
		stk->b[i] = temp;
	}
}