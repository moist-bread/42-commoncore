/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:40:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:09 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_putnbr_base(int nbr, char *base);
size_t	ft_strlen(const char *str);


/* int	main(void)
{
	int	testint = 2147483647;

	printf ("%d (correct number)\n", testint);
	printf (" (put number base)\n%d", ft_putnbr_base(testint, "0123456789ABCDEF"));
	;
	return (0);
} */

int ft_putnbr_base(int nbr, char *base)
{
	size_t len;
	long num;
    int counter;
	int	mod;

	len = ft_strlen(base);
	num = nbr;
    counter = 0;
	if (num < 0)
	{
		write (1, "-", 1);
		num = -num;
	}
	if (num > 9)
		counter += ft_putnbr_base(num / len, base);
	mod = num % len;
	write(1, &base[mod], 1);
    counter++;
    return(counter);	
}

/* void ft_putnbr_base(int nbr, char *base)
{
	size_t len;
	long num;
	int	mod;

	len = ft_strlen(base);
	num = nbr;
	if (num < 0)
	{
		write (1, "-", 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr_base(num / len, base);
	mod = num % len;
	write(1, &base[mod], 1);	
} */


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}