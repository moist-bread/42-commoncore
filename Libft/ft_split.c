/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:42 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/31 11:53:30 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);
char	*ft_segalloc(char const *s, char c, int len);
int		ft_seglen(char const *str, char c);
int		ft_segcount(char const *str, char c);
void	*ft_freestr(char **split, int i);

/*
int	main(void)
{
	int		i;
	char	chara;
	char	**result;
	int		count;
	char	*sentence;

	sentence = "Lorem ipsum ajshdah";
	i = 0;
	chara = ' ';
	result = ft_split(sentence, chara);
	count = ft_segcount(sentence, chara);
	printf("%i\n", count);
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i++;
	}
	ft_freestr(result, count + 1);
	return (0);
}
*/

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		segcount;
	char	**split;

	if (s == NULL)
		return (0);
	segcount = ft_segcount(s, c);
	split = malloc((segcount + 1) * sizeof(char *));
	if (split == NULL)
		return (0);
	i = 0;
	while (i < segcount)
	{
		while (*s == c)
			s++;
		len = ft_seglen(s, c);
		split[i] = ft_segalloc(s, c, len);
		if (split[i] == NULL)
			return (ft_freestr(split, segcount + 1));
		i++;
		s += len;
	}
	split[i] = 0;
	return (split);
}

int	ft_seglen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	ft_segcount(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char	*ft_segalloc(char const *s, char c, int len)
{
	int		j;
	char	*seg;

	j = 0;
	seg = malloc((len + 1) * sizeof(char));
	if (seg == NULL)
		return (0);
	while (s[j] != 0 && s[j] != c)
	{
		seg[j] = s[j];
		j++;
	}
	seg[j] = 0;
	return (seg);
}

void	*ft_freestr(char **split, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(split[i++]);
	free(split);
	return (NULL);
}
