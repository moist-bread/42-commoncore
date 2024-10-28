/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:03:22 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:03:29 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c);

/*
int	main(void)
{

	printf("return: %d \n", ft_isdigit('A'));
	printf("return: %d \n", ft_isdigit('!'));
	printf("return: %d \n", ft_isdigit('a'));
	printf("return: %d \n", ft_isdigit('1'));
	return (0);
}
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
