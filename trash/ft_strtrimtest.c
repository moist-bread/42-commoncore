#include <stdlib.h>
#include <stdio.h>

char *ft_strtrim(char const *s1, char const *set);
int ft_trimlen(char const *s1, char const *set);

int main(void)
{
    char const original[] = "olaboa";
    char const ref[] = "ab";

    printf("%s (original)\n%s (ref)\n", original, ref);
    printf("%s (return)", ft_strtrim(original, ref));
    // printf("%i (trim len)", ft_trimlen(original, ref));
    return (0);
}

/*
I DID IT WRONG BUT ILL FIX IT LATER WHEN I FINALLY
UNDERSTAND WHAT THE FUNTION IS SUPPOSE TO DO
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int n;
    int j;
    char *trimmed;

    i = 0;
    n = 0;
    trimmed = malloc((ft_trimlen(s1, set) + 1) * sizeof(char));
    if (trimmed == NULL)
        return (0);
    while (s1[i + n] != 0)
    {
        j = 0;
        while (s1[i + n] != set[j] && set[j] != 0)
            j++;
        if (s1[i + n] != set[j])
        {
            trimmed[i] = s1[i + n];
            i++;
        }
        else
            n++;
    }
    trimmed[i] = 0;
    return (trimmed);
}

int ft_trimlen(char const *s1, char const *set)
{
    int len;
    int i;
    int j;

    len = 0;
    i = 0;
    while (s1[i] != 0)
    {
        j = 0;
        while (s1[i] != set[j] && set[j] != 0)
            j++;
        if (s1[i] != set[j])
            len++;
        i++;
    }
    return (len);
}