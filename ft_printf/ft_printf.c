/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/05 18:56:25 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *input, ...);

int main()
{
    printf("(%%c test) %c\n", 'C');
    printf("(%%s test) %s\n", "boas");
    printf("(%%p test) %p\n", (void *)"void pointer");
    printf("(%%d test) %d\n", (int)-420.42);
    printf("(%%i test) %i\n", 420420);
    printf("(%%u test) %u\n", (unsigned int)420.42);
    printf("(%%x test) %x\n", 42);
    printf("(%%X test) %X\n", 42);
}