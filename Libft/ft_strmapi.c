/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:31 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 13:48:47 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlen(const char *str);
//char	ft_toupper(unsigned int index, char c);

/*
int	main(void)
{
	char	*str;

	str = "Hallo Ebery Nyan";
	printf("%s\n%s", str, ft_strmapi(str, ft_toupper));
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = s[i];
	return (str);
}

/*
char	ft_toupper(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

*/