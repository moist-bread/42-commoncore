#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int main(void)
{
    printf("(%%c test) %c\n", 'C');
    printf("(%%s test) %s\n", "boas");
    printf("(%%p test) %p\n", (void *)"void pointer");
	printf("(%%p test) %p\n", (void *)"what");
	printf("(%%p test) %p\n", (void *)"bruh");
    printf("(%%d test) %d\n", (int)-420.42);
    printf("(%%i test) %i\n", 420420);
    printf("(%%u test) %u\n", (unsigned int)420.42);
    printf("(%%x test) %x\n", 42);
    printf("(%%X test) %X\n", 42);
}

/* int ft_printf(const char *input, ...)
{
    int counter;
    int i;

    counter = 0;
    i = 0;
    while (input[i])
    {
        if (input[i] == '%')
        {
            counter += ft_itsapercent(&input[++i], str);
            i++;
        }
        else
        {
            write (1, &input[i++], 1);
            counter++;
        }
    }
    return(counter);
} */

/* int ft_itsapercent(const char *input, ...)
{
    int counter;

    if (input[0] == 'c')
        ;
    if (input[0] == 's')int	ft_putstr(char *str)
        counter = ft_putstr(str);
    if (input[0] == 'p')
        ;
    if (input[0] == 'd' || input[0] == 'i' || input[0] == 'u')
        counter = ft_putnbr_base(testint, "0123456789");
    if (input[0] == 'x')
        counter = ft_putnbr_base(testint, "0123456789abcdef");
    if (input[0] == 'x')
        counter = ft_putnbr_base(testint, "0123456789ABCDEF");
    if (input[0] == '%')
    {
        write (1, &input[0], 1);
        counter = 1;
    }
    return (counter);
} */

/* int ft_printf(const char *input, ...)
{
    va_list args;
    int counter;
    int idx;
    char c;
    char *s;
    void *p;
    int i;
    //unsigned int u;
    
    va_start(args, input);
    counter = 0;
    idx = 0;
    while (input[idx])
    {
        if (input[idx] == '%')
        {
            if (input[idx + 1] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                counter++;
            }
            if (input[idx + 1] == 's')
            {
                s = va_arg(args, char*);
                counter += ft_putstr(s);
            }
            if (input[idx + 1] == 'p')
            {
                p = va_arg(args, void *);    
                ;
            }
            if (input[idx + 1] == 'd' || input[idx + 1] == 'i' || input[idx + 1] == 'u')
            {
                i = va_arg(args, int);    
                counter += ft_putnbr_base(i, "0123456789");
            }
            if (input[idx + 1] == 'x')
            {
                i = va_arg(args, int);    
                counter += ft_putnbr_base(i, "0123456789abcdef");
            }
            if (input[idx + 1] == 'x')
            {
                i = va_arg(args, int);
                counter += ft_putnbr_base(i, "0123456789ABCDEF");
            }
            if (input[idx + 1] == '%')
            {
                write (1, &input[idx], 1);
                counter++;
            }
            idx += 2;
        }
        else
        {
            write (1, &input[idx++], 1);
            counter++;
        }
    }
    va_end(args);
    return(counter);
} */