/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:48 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/31 21:36:06 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

/*
int	main(void)
{
	const char	str[] = "bom dia flor do dia";

	printf("%s\n", ft_strdup(str));
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

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dup == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = src[i];
	return (dup);
}
