/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:54 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/04 10:45:05 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);

/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("%s (prefix)\n%s (suffix)\n", argv[1], argv[2]);
	printf("%s (return)\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (string == NULL)
		return (0);
	while (s1[i] != 0)
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = 0;
	return (string);
}
