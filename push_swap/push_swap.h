/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/16 16:58:23 by rduro-pe         ###   ########.fr       */
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
	int		bst_id_a;
	int		bst_id_b;
	int		cur_move;
}			t_moves;

typedef struct s_range
{
	int		high;
	int		high_id;
	int		low;
	int		low_id;
}			t_range;

// PRINTING FTS
void		print_stack(int *stack, int top_idx);
void		print_both_stacks(t_stacks *stk);

// ERROR CHECK FTS
int			input_processer(int argc, char **argv, t_stacks **stk, int spt);
int			input_check(char **argv);
int			int_check(char *argv);
int			overflow_check(char *str);
int			repeat_check(t_stacks *stk);

// HELPER FTS
t_stacks	*make_stacks(int argc, char **argv);
int			arg_counter(int argc, char **args);
void		free_stacks(t_stacks *stk);
int			free_args(char **args, int argc, int splitted);

// SORTING FTS
void		sort_stack(t_stacks *stk);
int			sort_check(int *stk, int top);
void		self_sort(t_stacks *stks, int *stk, int top);
int			rev_sort_check(int *stk, int top);
void		sort_calc(t_stacks *stk, t_moves *mover);
t_range		*stack_range(int *stk, int top_id);
void		exe_move(t_stacks *stk, int ba, int bb);

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