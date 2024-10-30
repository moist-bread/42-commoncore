/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:28:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/30 19:24:26 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);

void	*ft_memset(void *dest, int filler, size_t n);

int	main(void)
{
	char dest[30];
	char	*test2 = "AAAAAAAAA";
	ft_memset(dest, 'C', 5);

	printf("text1: %s text2: %s\n", dest, test2);
	printf("return: %lu \n", ft_strlcat(dest, test2, -1));
	printf("text1: %s text2: %s\n", dest, test2);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *dest, int filler, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (i < n)
		d[i++] = filler;
	return (dest);
}
/*
memset(dest, 'B', 4);
3 check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB")); showLeaks();
4 check(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA")); showLeaks();
memset(dest, 'C', 5);
5 check(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA")); showLeaks();
memset(dest, 'C', 15);
6 check(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA")); showLeaks();
*/	

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (destsize + src_len);
	i = dest_len;
	while (src[i] != 0 && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest_len + src_len);
}
