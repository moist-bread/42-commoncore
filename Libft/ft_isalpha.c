/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:00:37 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/28 11:00:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);

/*
int	main(void)
{

	printf("return: %d \n", ft_isalpha('A'));
	printf("return: %d \n", ft_isalpha('?'));
	printf("return: %d \n", ft_isalpha('a'));
	printf("return: %d \n", ft_isalpha('1'));
	return (0);
}
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
