/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:23:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/03/03 19:52:38 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	param_len(char const *str, char c);
static int	param_count(char const *str, char c);
static void	*ft_freestr(char **split, int i);
static void	sub_creator(int *len, char **split, const char *s, int i);

char	**command_separator(char const *s)
{
	int		i;
	int		len;
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = param_count(s, ' ');
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < count)
	{
		sub_creator(&len, split, s, i);
		if (!split[i++])
			return (ft_freestr(split, count));
		s += len;
	}
	split[i] = 0;
	return (split);
}

static void	sub_creator(int *len, char **split, const char *s, int i)
{
	while (*s == ' ' && *s)
		s++;
	*len = param_len(s, ' ');
	if (*s && *s == '\'')
		split[i] = ft_substr(s + 1, 0, *len - 2);
	else
		split[i] = ft_substr(s, 0, *len);
}

static int	param_count(char const *str, char c)
{
	int	count;
	int	string_flag;

	count = 0;
	string_flag = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str == '\'')
		{
			str++;
			count++;
			while (*str && *str != '\'')
				str++;
			while (*str && *str != c)
				str++;
		}
		if (*str && *str != c)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static int	param_len(char const *str, char c)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		while (str[i] && str[i] != c)
			i++;
	}
	else
	{
		while (str[i] && str[i] != c)
			i++;
	}
	return (i);
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
