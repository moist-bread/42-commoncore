/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:28:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/30 14:33:07 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);
/*
void	*ft_memset(void *dest, int filler, size_t n);

int	main(void)
{
	char dest[30];
	char	*test2 = "AAAAAAAAA";
	ft_memset(dest, 'B', 4);

	printf("text1: %s text2: %s\n", dest, test2);
	printf("return: %lu \n", ft_strlcat(dest, test2, 6));
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

memset(dest, 'B', 4);
3 check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB")); showLeaks();
4 check(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA")); showLeaks();
memset(dest, 'C', 5);
5 check(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA")); showLeaks();
memset(dest, 'C', 15);
6 check(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA")); showLeaks();
	
14 check(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1")); showLeaks();
15 check(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12")); showLeaks();
16 check(ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123")); showLeaks();
*/	

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (destsize + src_len);
	return (dest_len + src_len);
}
