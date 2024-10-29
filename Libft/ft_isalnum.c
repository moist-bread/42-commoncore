/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:59:53 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:00:07 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

/*
int	main(void)
{

	printf("return: %d \n", ft_isalnum('A'));
	printf("return: %d \n", ft_isalnum('?'));
	printf("return: %d \n", ft_isalnum('a'));
	printf("return: %d \n", ft_isalnum('1'));
	return (0);
}
*/

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}
