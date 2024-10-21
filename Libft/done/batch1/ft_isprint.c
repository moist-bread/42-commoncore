#include <stdio.h>

int ft_isprint(int c);

/*
int main(void)
{
    printf("return: %d \n", ft_isprint('A'));
    printf("return: %d \n", ft_isprint('?'));
    printf("return: %d \n", ft_isprint(163));
    printf("return: %d \n", ft_isprint('1'));
    return (0);
}
*/

int ft_isprint(int c)
{
    if (c < ' ' || c > '~')
        return (0);
    return (1);
}