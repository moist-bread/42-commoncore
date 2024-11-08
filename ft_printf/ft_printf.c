/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:58:25 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/08 12:49:41 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	main(void)
{
	int	cnt;

	cnt = ft_printf("text%%\th%c%s%d", 'C', "waaa", 32758);
	printf(" (my printf)\n");
	printf("%d (count)\n", cnt);
	printf("text%%\th%c%s%d (real printf)\n", 'C', "waaa", 32758);
    ft_printf("(%%p est) %p\n", (void *)-1);
	ft_printf("(%%p est) %p\n", (void *)1);
    ft_printf("(%%p tst) %p\n", (void *)15);
	ft_printf("(%%p est) %p\n", (void *)16);
    ft_printf("(%%p est) %p\n", (void *)17);
	ft_printf("(%%p tst) %p\n", (void *)0);
    cnt = ft_printf("%p %u", (void *)-1, (unsigned int)-1);
	ft_printf(" (my printf)\n");
	printf("%d (count)\n", cnt);
	printf("%p %u (real printf)", (void *)-1, (unsigned int)-1);
} */

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		cnt;

	va_start(args, input);
	cnt = 0;
	while (*input)
	{
		if (*input == '%')
			cnt += ft_ispercent(++input, args);
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

int	ft_ispercent(const char *input, va_list args)
{
	int		cnt;

	if (*input == 'c')
		cnt = ft_printchar(va_arg(args, int));
	if (*input == 's')
		cnt = ft_printstr(va_arg(args, char *));
	if (*input == 'p')
        cnt = ft_printptr(va_arg(args, unsigned long));
	if (*input == 'd' || *input == 'i')
		cnt = ft_prtnb_base(va_arg(args, int), "0123456789", 10);
	if (*input == 'u')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789", 10);
    if (*input == 'x')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (*input == 'X')
		cnt = ft_prtnb_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	if (*input == '%')
		cnt = ft_printchar('%');
	return (cnt);
}
/* 
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

int	ft_prtnb_base(long nbr, char *base, int len)
{
	int		cnt;
	int		mod;

	cnt = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
        cnt++;
	}
	if (nbr >= len)
		cnt += ft_prtnb_base(nbr / len, base, len);
	mod = nbr % len;
	write(1, &base[mod], 1);
	cnt++;
	return (cnt);
}

int	ft_printptr(unsigned long p)
{
	if(!p)
		return(ft_printstr("(nil)"));
	write(1, "0x", 2);
    return (ft_prtptr_base(p, "0123456789abcdef") + 2);    
}

int	ft_prtptr_base(unsigned long nbr, char *base)
{
	int		cnt;
	int		mod;

	cnt = 0;
	if (nbr >= 16)
		cnt += ft_prtnb_base(nbr / 16, base, 16);
	mod = nbr % 16;
	write(1, &base[mod], 1);
	cnt++;
	return (cnt);
} */
