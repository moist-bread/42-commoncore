/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 12:11:06 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*memchr(const void *s, int c, size_t n);

void	*memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != 0 && i < n)
	{
		if (str[i] == c)
			return ((void *)&str[i]);
		i++;
	}
	if (c == 0)
		return ((void *)&str[i]);
	else
		return (0);
}