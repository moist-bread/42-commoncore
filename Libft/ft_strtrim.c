/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 08:53:28 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);
int		ft_trimbegin(char const *s1, char const *set);
int		ft_trimend(char const *s1, char const *set);

/*
int	main(void)
{
	char const	original[] = "   xxx   xxx";
	char const	ref[] = " x";
	char		*s;

	s = ft_strtrim(original, ref);
	printf("%s (original)\n%s (ref)\n", original, ref);
	printf("%i (trim begin)\n", ft_trimbegin(original, ref));
	printf("%i (trim end)\n", ft_trimend(original, ref));
	printf("%s (return)\n", s);
	printf("%d(strcmp)\n", strcmp(s, ""));
	return (0);
}
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;
	char	*trimmed;

	if (s1 == 0)
		return (NULL);
	begin = ft_trimbegin(s1, set);
	end = ft_trimend(s1, set);
	i = 0;
	trimmed = malloc((end - begin + 1) * sizeof(char));
	if (trimmed == NULL)
		return (0);
	while (s1[begin] && begin < end)
		trimmed[i++] = s1[begin++];
	trimmed[i] = 0;
	return (trimmed);
}

int	ft_trimbegin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i++;
		else
			return (i);
	}
	return (0);
}

int	ft_trimend(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i--;
		else
			return (++i);
	}
	return (0);
}
