/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:27:12 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/30 16:16:24 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

/*
int	main(void)
{
	char	*string = NULL;

	printf("original string: %s\nstart: %i\n", string, 5);
	printf("substring: %s\n", ft_substr(string, 5, 5));
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	strlen;
	size_t	size;
	char	*substring;

	if (s == NULL)
		return (0);
	j = 0;
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (NULL);
	if (strlen - start < len)
		size = strlen - start;
	else
		size = len;
	substring = malloc((size + 1) * sizeof(char));
	if (substring == 0)
		return (NULL);
	while (s[start + j] != 0 && j < size)
	{
		substring[j] = s[start + j];
		j++;
	}
	substring[j] = 0;
	return (substring);
}

