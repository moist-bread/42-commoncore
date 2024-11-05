/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:40:47 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/08/31 18:47:36 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

/*
int	main(void)
{
	int	testint = 2147483647;

	printf ("%d (correct number)\n", testint);
	printf (" (put number)");
	ft_putnbr(testint);
	return (0);
}
*/

void	ft_putnbr(int nb)
{
	int	mod;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write (1, "-", 1);
			nb = -nb;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		mod = nb % 10 + 48;
		write(1, &mod, 1);
	}
}
