/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:19 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 12:20:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_toupper(unsigned int n, char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
int	main(void)
{
	char	*str;

	str = "Hallo Ebery Nyan";
	ft_striteri(str, ft_toupper);
	printf("%s", str);
}

void	ft_toupper(unsigned int n, char *str)
{
	if (str[n] >= 'A' && str[n] <= 'Z')
		printf("a");
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
		f(i++, s);
}
