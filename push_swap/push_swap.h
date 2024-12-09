/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/12 00:06:17 by rduro-pe         ###   ########.fr       */
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

// PRINTING FTS
void		print_stack(int *stack, int top_idx);
void		print_both_stacks(t_stacks *stk);

// ERROR CHECK FTS
int			input_processer(int argc, char **argv, t_stacks **stk, int spt);
int			input_check(char **argv);
int			int_check(char argv[]);
int			overflow_check(char *str);
int			repeat_check(t_stacks *stk);

// HELPER FTS
t_stacks	*make_stacks(int argc, char **argv);
int			arg_counter(int argc, char **args);
void		free_stacks(t_stacks *stk);
int			free_args(char **args, int argc, int splitted);

// SORTING FTS
void		sort_stack(t_stacks *stk);
void		self_sort(t_stacks *stks, int *stk, int top);
int			sort_check(int *stk, int top);

// OPERATION FTS
void		sa_do(t_stacks *stk);
void		sb_do(t_stacks *stk);
void		ss_do(t_stacks *stk);
void		pa_do(t_stacks *stk);
void		pb_do(t_stacks *stk);
void		ra_do(t_stacks *stk);
void		rb_do(t_stacks *stk);
void		rr_do(t_stacks *stk);
void		rra_do(t_stacks *stk);
void		rrb_do(t_stacks *stk);
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