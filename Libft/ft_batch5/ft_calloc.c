/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:04 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:31:05 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(long nmemb, long size);

// FIX FOR INT OVERFLOW AND IF BOTH VALS ARE 0

int	main(void)
{
	int	*ptr1;
	int	*ptr2;
	int	n;
	int	i;

	n = 5;
	printf("number of elements: %d\n", n);
	ptr1 = calloc(n, sizeof(int));
	ptr2 = ft_calloc(n, sizeof(int));
	if (ptr1 == NULL)
	{
		printf("(memory not allocated)\n");
		exit(0);
	}
	else
	{
		printf("(memory successfully allocated using calloc)\n");
		for (i = 0; i < n; ++i)
		{
			ptr1[i] = i + 1;
		}
		for (i = 0; i < n; ++i)
		{
			printf("%d, ", ptr1[i]);
		}
		printf("(calloc array)");
	}
	if (ptr2 == NULL)
	{
		printf("\n(memory not allocated)\n");
		exit(0);
	}
	else
	{
		printf("\n(memory successfully allocated using my ft)\n");
		for (i = 0; i < n; ++i)
		{
			ptr2[i] = i + 1;
		}
		for (i = 0; i < n; ++i)
		{
			printf("%d, ", ptr2[i]);
		}
		printf("(ft array)");
	}
	return (0);
}

void	*ft_calloc(long nmemb, long size)
{
	void *ptr;
	char array[nmemb * size];
	int i;

	if (nmemb == 0 && size == 0)
		return (1);
	if ((nmemb * size) > 2147483647 || (nmemb * size) < -2147483647)
		exit(0);
	i = 0;
	while (array[i] != 0)
	{
		array[i] = 0;
		i++;
	}
	ptr = &array;
	return (ptr);
}