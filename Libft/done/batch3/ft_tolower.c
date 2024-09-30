#include <stdio.h>

char ft_tolower(char c);

/*
int main(void)
{
    char test1 = ';';
    char test2 = 'W';

    printf("text:%c ", test1);
    printf("return: %c \n", ft_tolower(test1));
    printf("text:%c ", test2);
    printf("return: %c \n", ft_tolower(test2));
    return (0);
}
*/

char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}
