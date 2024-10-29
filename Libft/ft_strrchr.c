/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:34 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 12:17:20 by rduro-pe         ###   ########.fr       */
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
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (&s[i]);
		i--;
	}
	return (0);
}
