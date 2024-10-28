/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:02:51 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:02:54 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int c);

/*
int	main(void)
{
	printf("return: %d \n", ft_isascii('A'));
	printf("return: %d \n", ft_isascii('?'));
	printf("return: %d \n", ft_isascii(163));
	printf("return: %d \n", ft_isascii('1'));
	return (0);
}
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
