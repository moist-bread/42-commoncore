/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:43 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 08:41:39 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

/*
int	main(void)
{
	char	teststr1[] = "\n   -95345\n67++8-";
	char	teststr2[] = "   +-+++-+1234ab5-67+";

	printf("original str: %s\natoi output: %d\n", teststr1, atoi(teststr1));
	printf("my   output: %d\n", ft_atoi(teststr1));
	printf("original str: %s\natoi output: %d\n", teststr2, atoi(teststr2));
	printf("my   output: %d\n", ft_atoi(teststr2));
	return (0);
}
*/

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - 48);
	if (sign)
		result = -result;
	return (result);
}
