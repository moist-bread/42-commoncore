#include <string.h>
#include <stdio.h>

int ft_memcmp(char *s1, char *s2, long n);

int main(void)
{
}

int ft_memcmp(char *s1, char *s2, long n)
{
    int i;

    i = 0;
    return (s1[i] - s2[i]);
}