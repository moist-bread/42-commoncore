/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:03:49 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:03:53 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c);

/*
int	main(void)
{
	printf("return: %d \n", ft_isprint('A'));
	printf("return: %d \n", ft_isprint('?'));
	printf("return: %d \n", ft_isprint(163));
	printf("return: %d \n", ft_isprint('1'));
	return (0);
}
*/

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
