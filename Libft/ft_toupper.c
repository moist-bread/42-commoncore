/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:49:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:50:05 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(char c);

/*
int	main(void)
{
	char test1 = ';';
	char test2 = 't';

	printf("text:%c ", test1);
	printf("return: %c \n", ft_toupper(test1));
	printf("text:%c ", test2);
	printf("return: %c \n", ft_toupper(test2));
	return (0);
}
 */
int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
