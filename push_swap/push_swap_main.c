/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:28:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/09 18:41:53 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*make_stacks(int argc, char *argv[]);
void	print_stack(int *stack, int top_idx);
void	rb_do(t_stacks *stk);
int		int_check(char argv[]);
int		arg_counter(int argc, char **args);
void	sort_stack(t_stacks *stk);

int	main(int argc, char *argv[])
{
	t_stacks	*stk;
	char	**args;

	if (argc <= 1)
		return (0); // INSTEAD OF RETURN "GIVE PROMPT BACK"
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	argc = arg_counter(argc, args);
	if (argc <= 1)
		return (0); // INSTEAD OF RETURN "GIVE PROMPT BACK"
	if (input_check(args))
		return (1);
	stk = make_stacks(argc, args);
	if (!stk)
		return (0);
	if (repeat_check(stk))
		return (1);
	sort_stack(stk);
	//ft_printf("(args)%i\n", argc);
	// print_both_stacks(stk);
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

/* int	main(void)
{
	int		i;
	char	chara;
	char	**result;
	int		count;
	char	*sentence;

	sentence = "hello!";
	chara = ' ';
	//sentence = "Lorem ipsum ajshdah";
	//chara = ' ';
	i = 0;
	result = ft_split(sentence, chara);
	count = ft_segcount(sentence, chara);
	printf("%i\n", count);
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i++;
	}
	ft_freestr(result, count + 1);
	return (0);
} */
void	sort_stack(t_stacks *stk)
{
	
}

int		arg_counter(int argc, char **args)
{
	int	count;

	count = 0;
	if (argc == 1)
		return(1);
	if (argc > 2)
		return(--argc);
	while(args[count])
		count++;
	return(count);
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
		stk->a[stk->atop_id] = ft_atoi(argv[argc - stk->atop_id -1]);
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
