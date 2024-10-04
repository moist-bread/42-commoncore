#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(char const *s1, char const *s2);
int ft_strlen(char const *str);

/*
int main(int argc, char *argv[])
{
    (void)argc;
    printf("%s (prefix)\n%s (suffix)\n", argv[1], argv[2]);
    printf("%s (return)\n", ft_strjoin(argv[1], argv[2]));
    return (0);
}
*/

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    char *string;

    i = 0;
    j = 0;
    string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (string == NULL)
        return (0);
    while (s1[i] != 0)
    {
        string[i] = s1[i];
        i++;
    }
    while (s2[j] != 0)
    {
        string[i + j] = s2[j];
        j++;
    }
    string[i + j] = 0;
    return (string);
}

int ft_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}