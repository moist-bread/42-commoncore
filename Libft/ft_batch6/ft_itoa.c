#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int n);
int ft_intlen(int n);

int main(void)
{
    int number = 123;

    printf("%d (original)\n", number);
    printf("%s(my itoa)\n", ft_itoa(number));
    return (0);
}

char *ft_itoa(int n)
{
    int i;
    char *number;

    number = malloc((ft_intlen(n) * sizeof(char)) + 1);
    i = ft_intlen(n) - 1;
    if (n < 0)
    {
        n = -n;
        i++;
        number[0] = '-';
    }
    number[i + 1] = '\0';
    while (n > 9)
    {
        number[i] = (n % 10) + 48;
        n = n / 10;
    }
    return (number);
}

int ft_intlen(int n)
{
    int i;

    i = 0;
    if (n < 0)
        n = -n;
    while (n >= 1)
    {
        n = n / 10;
        i++;
    }
    return (i);
}