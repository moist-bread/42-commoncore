/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:57 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/29 12:17:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);
int		ft_trimbegin(char const *s1, char const *set);
int		ft_trimend(char const *s1, char const *set);

/*
int	main(void)
{
	char const	original[] = "aaaaaabbbolaboababababababababbabaabbbaa";
	char const	ref[] = "ab";

	printf("%s (original)\n%s (ref)\n", original, ref);
	printf("%i (trim begin)\n", ft_trimbegin(original, ref));
	printf("%i (trim end)\n", ft_trimend(original, ref));
	printf("%s (return)", ft_strtrim(original, ref));
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
		return (0);
	begin = ft_trimbegin(s1, set);
	end = ft_trimend(s1, set);
	i = 0;
	trimmed = malloc((end - begin + 2) * sizeof(char));
	if (trimmed == NULL)
		return (0);
	while (s1[begin] != 0 && begin <= end)
		trimmed[i++] = s1[begin++];
	trimmed[i] = 0;
	return (trimmed);
}

int	ft_trimbegin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != 0)
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
	while (s1[i] != 0)
		i++;
	i--;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != 0)
			j++;
		if (s1[i] == set[j])
			i--;
		else
			return (i);
	}
	return (0);
}
