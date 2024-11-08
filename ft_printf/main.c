/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:53:20 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:21 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*str;

	str = 0;
	printf("%d(counter s)\n", printf("(%%s test) %s\n", str));
	printf("%d(counter p)\n", printf("(%%p test) %p\n", (void *)0));
}

/* int main(void)
{
	printf("(%%p test) %p\n", (void *)-1);
	printf("(%%p test) %p\n", (void *)1);
	printf("(%%p test) %p\n", (void *)15);
	printf("(%%p test) %p\n", (void *)16);
	printf("(%%p test) %p\n", (void *)17);
	printf("(%%p test) %p\n", (void *)0);
} */

/* int main(void)
{
	void *p = 0;
	printf("(%%c test) %c\n", 'C');
	printf("(%%s test) %s\n", "boas");
	printf("(%%p test) %p\n", (void *)"void pointer");
	printf("(%%p test) %p\n", (void *)"what");
	printf("(%%p test) %p\n", p);
	printf("(%%d test) %d\n", (int)-420.42);
	printf("(%%i test) %i\n", 420420);
	printf("(%%u test) %u\n", (unsigned int)-2);
	printf("(%%x test) %x\n", 10);
	printf("(%%X test) %X\n", 11);
} */