/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/17 12:54:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

// ERROR CHECK FTS
int			input_processer(int argc, char **argv, t_stacks **stk, int spt);
int			input_check(char **argv);
int			int_check(char *argv);
int			overflow_check(char *str);
int			repeat_check(t_stacks *stk);

// MAKE HELPERS FTS
int			arg_counter(int argc, char **args);
t_stacks	*make_stacks(int argc, char **argv);
int			free_args(char **args, int argc, int splitted);
void		free_stacks(t_stacks *stk);

// PRINTING FTS
void		print_stack(int *stack, int top_idx);
void		print_both_stacks(t_stacks *stk);
void		print_dists(int id_a, int id_b, int dist_a, int dist_b);
void		print_moves(t_moves *mover);

// SORTING FTS
void		sort_stack(t_stacks *stk);

// SORT HELPERS FTS
int			sort_check(int *stk, int top);
int			rev_sort_check(int *stk, int top);
void		self_sort(t_stacks *stks, int *stk, int top);
int			dist_calc(int id, int top, t_moves *mover, int flag);

// SORT CALC FTS
void		sort_calc(t_stacks *stk, t_moves *mover);
t_range		*stack_range(int *stk, int top_id);
int			place_finder(int id_a, t_stacks *stk, t_range *range);
int			curmov_calc(int dist_a, int dist_b, int bt, t_moves *mover);
void		is_the_best(int id_a, int id_b, t_moves *mover);

// EXECUTE FTS
void		exe_move(t_stacks *stk, t_moves *mover);
void		exe_rot(int *dist, int bst_id, int top_id, t_stacks *stk);

// OPERATION FTS
void		sa_do(t_stacks *stk, int flag);
void		sb_do(t_stacks *stk, int flag);
void		ss_do(t_stacks *stk);
void		pa_do(t_stacks *stk);
void		pb_do(t_stacks *stk);
void		ra_do(t_stacks *stk, int flag);
void		rb_do(t_stacks *stk, int flag);
void		rr_do(t_stacks *stk);
void		rra_do(t_stacks *stk, int flag);
void		rrb_do(t_stacks *stk, int flag);
void		rrr_do(t_stacks *stk);

// PRINTF FTS
int			ft_printf(const char *input, ...);
int			ft_ispercent(const char *input, va_list args);
int			ft_printchar(int c);
int			ft_printstr(char *str);
int			ft_prtnb_base(long nbr, char *base, int len);
int			ft_printptr(unsigned long p, int flag);

// LIBFT FTS
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);

#endif