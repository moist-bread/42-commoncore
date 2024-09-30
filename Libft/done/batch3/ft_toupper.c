#include <stdio.h>

char ft_toupper(char c);

/*
int main(void)
{
    char test1 = ';';
    char test2 = 't';

    printf("text:%c ", test1);
    printf("return: %c \n", ft_toupper(test1));
    printf("text:%c ", test2);
    printf("return: %c \n", ft_toupper(test2));
    return (0);
}
*/
char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}