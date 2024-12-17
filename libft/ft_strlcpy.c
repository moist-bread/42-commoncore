/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:28:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/31 12:59:24 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
/*
void	*ft_memset(void *dest, int filler, size_t n);

int	main(void)
{
	char	test4[] = "coucou";

	//char	test1[] = "ABCDEF1234567";
	//char	test2[] = "123";
	char	test3[10]; ft_memset(test3, 'A', 10);
	test3[0] = 'c';
	test3[1] = 0;
	//printf("text1: %s text2: %s\n", test1, test2);
	//printf("return: %u \n", strlcpy(test1, test2, 13));
	//printf("text1: %s text2: %s\n", test1, test2);
	printf("text1: %s text2: %s\n", test3, test4);
	printf("return: %lu \n", ft_strlcpy(test3, test4, -1));
	printf("text1: %s text2: %s\n", test3, test4);
	return (0);
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (src_len);
}
