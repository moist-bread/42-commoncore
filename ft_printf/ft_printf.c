/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:55 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/06 18:07:16 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *input, ...);
int ft_itsapercent(const char *input, ...);
void	ft_putstr(char *str);

int main(void)
{
    ft_printf("text%%\th");
    /* printf("(%%c test) %c\n", 'C');
    printf("(%%s test) %s\n", "boas");
    printf("(%%p test) %p\n", (void *)"void pointer");
    printf("(%%d test) %d\n", (int)-420.42);
    printf("(%%i test) %i\n", 420420);
    printf("(%%u test) %u\n", (unsigned int)420.42);
    printf("(%%x test) %x\n", 42);
    printf("(%%X test) %X\n", 42); */
}
/* int ft_printf(const char *input, ...)
{
    va_list args;
    int counter;
    char *x;
    
    va_start(args, input);
    x = va_arg(args, char *);
    counter = 0;
    while (x)
    {
        counter++;
        x = va_arg(args, char *);
    }
    va_end(args);
    return(counter);
} */

int ft_printf(const char *input, ...)
{
    int counter;
    int i;

    counter = 0;
    i = 0;
    while (input[i])
    {
        if (input[i] == '%')
        {
            counter += ft_itsapercent(&input[++i]);
            i++;
        }
        else
        {
            write (1, &input[i++], 1);
            counter++;
        }
    }
    return(counter);
}

int ft_itsapercent(const char *input, ...)
{
    int counter;

    if (input[0] == '%')
    {
        write (1, &input[0], 1);
        counter = 1;
    }
    if (input[0] == 's')
    {
        write (1, &input[0], 1);
        counter = ft_putstr(args);
    }
    return (counter);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

// in the input, count the amount of % not followed by a %
// detect what vartype itll be and redirect it to the corresponding
// printer function
// dont forget to just print them normally