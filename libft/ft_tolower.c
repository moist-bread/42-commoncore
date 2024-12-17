/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:45:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 10:46:01 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c);

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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
