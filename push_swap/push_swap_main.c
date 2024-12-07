/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/07 21:07:10 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stacks	*make_stacks(int argc, char *argv[]);
void	print_stack(int *stack, int top_idx);
int input_checker(int argc, char *argv[]);
void	rb_do(stacks *stk);
int	is_num(char argv[]);
int	int_check(const char *str);

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
		error += is_num(argv[i++]);
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

int	is_num(char argv[])
{
	int j;
	
	j = -1;
	if(argv[0] == '-' || argv[0] == '+')
		j++;
	while(argv[++j])
		if (!ft_isdigit(argv[j]))
			return(1);
	if (!int_check(argv))
		return(1);
	return(0);
}

int	int_check(const char *str)
{
	long	result;
	long	verif;
	int	sign;
	int	i;

	result = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - 48);
	if (sign)
		result = -result;
	verif = result * 50;
	if (verif / 50 != result) // long overflow
		return (0);
	if(result < -2147483648 || result > 2147483647)
		return (0);
	return (1);
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
