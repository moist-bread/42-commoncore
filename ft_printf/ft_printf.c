/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/07 18:07:36 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *input, ...);
int		ft_itsapercent(const char *input, va_list args);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int     ft_prtnb_base(int nbr, char *base, int len);

int	main(void)
{
	int	cnt;

	// cnt = ft_printf("text");
	cnt = ft_printf("text%%\th%c%s%d%x%X%s", 'C', "waaa", 32758, 42, 42, "");
	printf("\n");
	printf("%d (cnt)\n", cnt);
	printf("text%%\th%c%s%d%x%X%s (normal printf)", 'C', "waaa", 32758, 42, 42, "");
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		cnt;

	va_start(args, input);
	cnt = 0;
	while (*input)
	{
		if (*input == '%')
			cnt += ft_itsapercent(++input, args);
		else
		{
			write(1, &*input, 1);
			cnt++;
		}
		input++;
	}
	va_end(args);
	return (cnt);
}

int	ft_itsapercent(const char *input, va_list args)
{
	int		cnt;

	if (*input == 'c')
		cnt = ft_printchar(va_arg(args, int));
	if (*input == 's')
		cnt = ft_printstr(va_arg(args, char *));
	if (*input == 'p')
        cnt = ft_prtnb_base(va_arg(args, unsigned long int), "0123456789", 10);
	if (*input == 'd' || *input == 'i')
		cnt = ft_prtnb_base(va_arg(args, int), "0123456789", 10);
	if (*input == 'u')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789", 16);
    if (*input == 'x')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (*input == 'X')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	if (*input == '%')
		cnt = ft_printchar('%');
	return (cnt);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	cnt;

    if (!str)
        str = "(null)";
    cnt = 0;
	while (*str)
	{
        write(1, &*str++, 1);
		cnt++;
	}
	return (cnt);
}

int	ft_prtnb_base(int nbr, char *base, int len)
{
	long	num;
	int		cnt;
	int		mod;

	num = nbr;
	cnt = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
		cnt += ft_prtnb_base(num / len, base, len);
	mod = num % len;
	write(1, &base[mod], 1);
	cnt++;
	return (cnt);
}
