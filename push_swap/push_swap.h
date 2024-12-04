/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/04 19:38:19 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stacks
{
	int	*a;
	int	atop_id;
	int	*b;
	int	btop_id;
}		stacks;

//PRINTING FTS
int		print_stack(int *stack, int len);

//HELPER FTS
stacks	*make_stacks(int argc, char *argv[]);

//OPERATION FTS
void	sa_do(stacks *stk);
void	sb_do(stacks *stk);
void	ss_do(stacks *stk);
void	pa_do(stacks *stk);
void	pb_do(stacks *stk);
void	ra_do(stacks *stk);
void	rb_do(stacks *stk);

//PRINTF FTS
int	ft_printf(const char *input, ...);
int	ft_ispercent(const char *input, va_list args);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_prtnb_base(long nbr, char *base, int len);
int	ft_printptr(unsigned long p);
int	ft_prtptr_base(unsigned long nbr, char *base);

//LIBFT FTS
int	ft_atoi(const char *str);

#endif