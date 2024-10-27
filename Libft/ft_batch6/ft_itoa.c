/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:39 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:31:40 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);
int		ft_intlen(int n);

int	main(void)
{
	int	number;

	number = -2147483647;
	printf("%d (original)\n", number);
	printf("%s (my itoa)\n", ft_itoa(number));
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	int		minval;
	char	*number;

	i = ft_intlen(n) - 1;
	minval = 0;
	number = malloc((i + 2) * sizeof(char));
	if (number == NULL)
		return (0);
	if (n == -2147483648)
	{
		n = -2147483647;
		minval++;
	}
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	number[i + 1] = '\0';
	while (n > 9)
	{
		number[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	number[i] = n + 48;
	if (minval == 1)
		number[10] = '8';
	return (number);
}

int	ft_intlen(int n)
{
	int i;

	i = 0;

	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}