/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/07 19:36:27 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stacks
{
	int	*a;
	int	atop_id;
	int	*b;
	int	btop_id;
}		stacks;

// PRINTING FTS
void	print_stack(int *stack, int top_idx);
void	print_both_stacks(stacks *stk);

// HELPER FTS
stacks	*make_stacks(int argc, char *argv[]);

// OPERATION FTS
void	sa_do(stacks *stk);
void	sb_do(stacks *stk);
void	ss_do(stacks *stk);
void	pa_do(stacks *stk);
void	pb_do(stacks *stk);
void	ra_do(stacks *stk);
void	rb_do(stacks *stk);
void	rr_do(stacks *stk);
void	rra_do(stacks *stk);
void	rrb_do(stacks *stk);
void	rrr_do(stacks *stk);

// PRINTF FTS
int		ft_printf(const char *input, ...);
int		ft_ispercent(const char *input, va_list args);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_prtnb_base(long nbr, char *base, int len);
int		ft_printptr(unsigned long p, int flag);

// LIBFT FTS
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif