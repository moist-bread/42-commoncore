/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:42 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/09 17:22:42 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	ft_seglen(char const *str, char c);
static int	ft_segcount(char const *str, char c);
static void	*ft_freestr(char **split, int i);

/* int	main(void)
{
	int		i;
	char	chara;
	char	**result;
	int		count;
	char	*sentence;

	sentence = "hello!";
	chara = ' ';
	//sentence = "Lorem ipsum ajshdah";
	//chara = ' ';
	i = 0;
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
} */

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		segcount;
	char	**split;

	if (!s)
		return (NULL);
	segcount = ft_segcount(s, c);
	split = malloc((segcount + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < segcount)
	{
		while (*s == c && *s)
			s++;
		len = ft_seglen(s, c);
		split[i] = ft_substr(s, 0, len);
		if (!split[i++])
			return (ft_freestr(split, segcount));
		s += len;
	}
	split[i] = 0;
	return (split);
}

static int	ft_seglen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_segcount(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static void	*ft_freestr(char **split, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		free(split[i++]);
	free(split);
	return (NULL);
}
