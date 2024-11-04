/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:46:40 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 10:46:42 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c);

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
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
