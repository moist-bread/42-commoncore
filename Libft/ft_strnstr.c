/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:27 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 12:17:24 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n);

/*
int	main(void)
{
	const char	text[] = "goodmorning and goodnight";
	const char	pin[] = "dm";

	printf("text:'%s'\npin :'%s'\n", text, pin);
	printf("my return:%s \n", ft_strnstr(text, pin, 4));
	return (0);
}
 */

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	pin;
	char	*s;

	pin = 0;
	s = (char *)str;
	if (to_find[0] == '\0')
		return (s);
	while (str[pin] != '\0' && pin < len)
	{
		if (str[pin] == to_find[0])
		{
			i = 0;
			while (str[pin + i] == to_find[i] && to_find[i] != '\0' && pin
				+ i < len)
				i++;
			if (to_find[i] == '\0')
				return (&s[pin]);
		}
		pin++;
	}
	return (0);
}
