/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:04 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 22:31:50 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *dest, int filler, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
		return (0);
	array = malloc(nmemb * size);
	if (array == 0)
		return (0);
	ft_memset(array, 0, nmemb * size);
	return (array);
}
/*
void	*ft_memset(void *dest, int filler, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = filler;
		i++;
	}
	return (dest);
}
*/
