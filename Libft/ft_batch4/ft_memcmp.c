/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:30:58 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/10/27 10:30:59 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(char *s1, char *s2, long n);

int	main(void)
{
}

int	ft_memcmp(char *s1, char *s2, long n)
{
	int i;

	i = 0;
	return (s1[i] - s2[i]);
}