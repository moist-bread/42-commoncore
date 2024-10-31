/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:19 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/31 12:59:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	iter(unsigned int i, char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
int	main(void)
{
	char	str[] = "0000000000";

	ft_striteri(str, iter);
	printf("%s", str);
}

void	iter(unsigned int i, char *s)
{
	*s += i;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
