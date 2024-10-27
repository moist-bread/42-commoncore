/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:23 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:29:24 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

/*
int	main(void)
{
	const char	test1[] = "ABe";
	const char	test2[] = "BCD";
	const char	test3[] = "123b";
	const char	test4[] = "123a";
	const char	test5[] = "wordS";
	const char	test6[] = "wordY";

	printf("text1:%s text2:%s\n", test1, test2);
	printf("n = 0; return: %d (mine)\n", ft_strncmp(test1, test2, 0));
	printf("n = 0; return: %d (correct)\n", strncmp(test1, test2, 0));
	printf("text1:%s text2:%s\n", test3, test4);
	printf("n = 3; return: %d (mine)\n", ft_strncmp(test3, test4, 3));
	printf("n = 3; return: %d (correct)\n", strncmp(test3, test4, 3));
	printf("text1:%s text2:%s\n", test5, test6);
	printf("n = 4; return: %d (mine)\n", ft_strncmp(test5, test6, 4));
	printf("n = 4; return: %d (correct)\n", strncmp(test5, test6, 4));
	return (0);
}
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	while (i + 1 < n && (s1[i] != '\0' || s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
