/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:28:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:28:52 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);

/*
int	main(void)
{
	char	test1[10] = "ABC";
	char	test2[] = "DEFG";

	printf("text1: %s text2: %s\n", test1, test2);
	printf("return: %lu \n", ft_strlcat(test1, test2, 10));
	return (0);
}
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

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}