#include <stdlib.h>
#include <stdio.h>

char *ft_strtrim(char const *s1, char const *set);

int main(void)
{
    char const original[] = "ola";
    char const ref[] = "a";

    printf("%s (original)\n%s (ref)\n", original, ref);
    printf("%s (return)", ft_strtrim(original, ref));
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *trimmed;

    trimmed = malloc(ft_trimlen(s1, set) * sizeof(char));
}

int ft_trimlen(char const *s1, char const *set)
{
    int i;

    i = 0;
    while (s1[i] != 0)
    {
        if (s1[i] == set)
            return (i);
        i++;
    }

    if (set == 0)
        return (i);
    else
        return (0);
}