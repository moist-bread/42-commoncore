#include <stdio.h>

int ft_isascii(int c);

/*
int main(void)
{
    printf("return: %d \n", ft_isascii('A'));
    printf("return: %d \n", ft_isascii('?'));
    printf("return: %d \n", ft_isascii(163));
    printf("return: %d \n", ft_isascii('1'));
    return (0);
}
*/

int ft_isascii(int c)
{
    if (c < 0 || c > 127)
        return (0);
    return (1);
}