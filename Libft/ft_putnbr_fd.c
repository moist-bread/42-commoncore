/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:11 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 12:20:37 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd);

/*
int	main(void)
{
	int	testint;

	testint = 2147483647;
	printf("%d (correct number)\n", testint);
	printf(" (put number)");
	ft_putnbr_fd(testint, 1);
	return (0);
}
*/

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		mod = n % 10 + 48;
		write(fd, &mod, 1);
	}
}
