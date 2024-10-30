/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:04 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/30 16:50:07 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	
	if (nmemb == 0 || size == 0 || (nmemb + size) < nmemb || (nmemb * size) < 0)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == 0)
		return (0);
	ft_bzero(array, nmemb * size);
	return (array);
}
/*
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}
*/
