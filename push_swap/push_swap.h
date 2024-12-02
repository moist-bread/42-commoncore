/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/02 22:26:48 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//SWAP FTS

//PRINTF FTS
int	ft_printf(const char *input, ...);
int	ft_ispercent(const char *input, va_list args);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_prtnb_base(long nbr, char *base, int len);
int	ft_printptr(unsigned long p);
int	ft_prtptr_base(unsigned long nbr, char *base);

#endif