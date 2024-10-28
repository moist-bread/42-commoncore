/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:35:33 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:35:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(char c);

/*
int	main(void)
{
	char test1 = ';';
	char test2 = 'E';

	printf("text:%c ", test1);
	printf("return: %c \n", ft_tolower(test1));
	printf("text:%c ", test2);
	printf("return: %c \n", ft_tolower(test2));
	return (0);
}
 */

int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
