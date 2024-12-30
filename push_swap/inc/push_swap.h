/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/29 00:13:05 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBS
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// STRUCTS
typedef struct s_stacks
{
	int		*a;
	int		atop_id;
	int		*b;
	int		btop_id;
}			t_stacks;

typedef struct s_moves
{
	int		bst_move;
	int		bst_rot;
	int		bst_id_a;
	int		bst_id_b;
	int		cur_move;
	int		cur_rot;
}			t_moves;

typedef struct s_range
{
	int		high;
	int		high_id;
	int		low;
	int		low_id;
}			t_range;

typedef struct s_highest
{
	int		top_high;
	int		low_high;
}			t_highest;

// ERROR CHECK
int			input_processer(int argc, char **argv, t_stacks **stk, int spt);
int			input_check(char **argv);
int			int_check(char *argv);
int			overflow_check(char *str);
int			repeat_check(t_stacks *stk);

// MAKE STACK
int			arg_counter(int argc, char **args);
t_stacks	*make_stacks(int argc, char **argv);
int			free_args(char **args, int argc, int splitted);
void		free_stacks(t_stacks *stk);

// SORTING
void		sort_stack(t_stacks *stk);
void		self_sort_3(t_stacks *stks, int *stk, int top);
void		self_sort_5(t_stacks *stks, int *stk, int top);
void		initial_sort(t_stacks *stk);
void		final_sort(t_stacks *stk);

// SORT HELPERS
int			sort_check(int *stk, int top);
int			semi_sort_check(int *stk, int top);
t_moves		*set_mover(void);
int			dist_calc(int id, int top, t_moves *mover, int flag);
void		stack_shift(t_stacks *stk);

// QUICK SORT
t_highest	*highest_elems(t_stacks *stk);
int			pivot_picker(int *qs, int last);
void		ft_swap(int *a, int *b);
void		quick_sort(int *qs, int start, int pivot);

// SORT CALC
void		sort_calc(int id_a, t_stacks *stk, t_moves *mover, t_highest *high);
t_range		*stack_range(int *stk, int top_id);
int			place_finder(int id_a, t_stacks *stk, t_range *range);
int			curmov_calc(int dist_a, int dist_b, int bt, t_moves *mover);
void		is_the_best(int id_a, int id_b, t_moves *mover);

// EXECUTE
void		exe_move(t_stacks *stk, t_moves *mover);
void		exe_rot(int *dist, int bst_id, t_stacks *stk, int flag);

// OPERATIONS
void		sa_do(t_stacks *stk, int flag);
void		sb_do(t_stacks *stk, int flag);
void		ss_do(t_stacks *stk, int flag);
void		pa_do(t_stacks *stk, int flag);
void		pb_do(t_stacks *stk, int flag);
void		ra_do(t_stacks *stk, int flag);
void		rb_do(t_stacks *stk, int flag);
void		rr_do(t_stacks *stk, int flag);
void		rra_do(t_stacks *stk, int flag);
void		rrb_do(t_stacks *stk, int flag);
void		rrr_do(t_stacks *stk, int flag);

// PRINTING
void		print_stack(int *stack, int top_idx);
void		print_both_stacks(t_stacks *stk);
void		print_dists(int id_a, int id_b, int dist_a, int dist_b);
void		print_moves(t_moves *mover, t_stacks *stk);

#endif