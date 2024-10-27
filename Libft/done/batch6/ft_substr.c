/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:27:12 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:27:20 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strchrloc(char const *str, unsigned int c);

/*
int	main(void)
{
	char			string[] = "bom dia, flor do dia";
	unsigned int	character;

	character = 'a';
	printf("original string: %s\nstart: %c\n", string, character);
	printf("substring: %s\n", ft_substr(string, character, 5));
	return (0);
}
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	j;
	char	*substring;

	i = ft_strchrloc(s, start);
	j = 0;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == 0)
		return (NULL);
	while (s[i + j] != 0 && j < len)
	{
		substring[j] = s[i + j];
		j++;
	}
	substring[j] = 0;
	return (substring);
}

int	ft_strchrloc(char const *str, unsigned int c)
{
	int i;
	int chara;

	i = 0;
	chara = c;
	while (str[i] != 0)
	{
		if (str[i] == chara)
			return (i);
		i++;
	}
	if (chara == 0)
		return (i);
	else
		return (0);
}