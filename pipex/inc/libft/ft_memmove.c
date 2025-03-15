/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:41 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/15 11:37:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s && (s || d))
	{
		i = 0;
		while (i < (int)n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s || d)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
