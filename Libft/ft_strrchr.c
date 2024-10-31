/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:34 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/31 12:59:51 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c);

/*
int	main(void)
{
	char	*string;
	int		character;

	string = "bom dia, flor do dias";
	character = 'd';
	printf("original: %s\npin: %c\n", string, character);
	printf("search result: %s (correct)\n", strrchr(string, character));
	printf("search result: %s (mine)\n", ft_strrchr(string, character));
	return (0);
}
 */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
