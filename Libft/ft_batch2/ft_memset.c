/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:44 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:30:45 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// void *ft_memset(void *dest, int filler, long n);

int	main(void)
{
	void	*string[21];
	char	*result;

	result = memset(string, 'A', 5);
	printf("return: %s \n", result);
	result = memset(string, 'B', 10);
	printf("return: %s \n", result);
	result = memset(string, 'C', 15);
	printf("return: %s \n", result);
	result = memset(string, 'D', 20);
	printf("return: %s \n", result);
	return (0);
}
/*
void	*ft_memset(void *dest, int filler, long n)
{
	int i;

	while (dest[i] != 0 && i > n)
	{
		dest[i] = filler;
		i++;
	}
}*/