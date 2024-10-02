#include <stdio.h>
#include <string.h>

char *ft_strrchr(char *str, int c);
int ft_strlen(char *str);

/*
int main(void)
{
    char *string = "bom dia, flor do dias";
    int character = 'd';

    printf("original: %s\npin: %c\n", string, character);
    printf("search result: %s (correct)\n", strrchr(string, character));
    printf("search result: %s (mine)\n", ft_strrchr(string, character));
    return (0);
}
*/

char *ft_strrchr(char *str, int c)
{
    int i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if (str[i] == c)
            return (&str[i]);
        i--;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}