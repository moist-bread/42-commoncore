/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:27:12 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/01 13:46:04 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
/*
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*string;
	char	*s;

	string = "tripouille";
	s = ft_substr(string, 100, 1);
	printf("original string: %s\nstart: %i\n", string, 100);
	printf("substring: %s\n", s);
	printf("%d (diff)", ft_strcmp(s, ""));
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
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] - s2[i]));
			break ;
		}
		i++;
	}
	return ((s1[i] - s2[i]));
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
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (strlen - start < len)
		size = strlen - start;
	else
		size = len;
	substring = malloc((size + 1) * sizeof(char));
	if (substring == 0)
		return (NULL);
	j = 0;
	while (s[start + j] != 0 && j < size)
	{
		substring[j] = s[start + j];
		j++;
	}
	substring[j] = 0;
	return (substring);
}
