#include <string.h>
#include <stdio.h>

// void *ft_memset(void *dest, int filler, long n);

int main(void)
{
    void *string[21];
    char *result = memset(string, 'A', 5);
    printf("return: %s \n", result);
    result = memset(string, 'B', 10);
    printf("return: %s \n", result);
    result = memset(string, 'C', 15);
    printf("return: %s \n", result);
    result = memset(string, 'D', 20);
    printf("return: %s \n", result);

    return (0);
}
/*
void *ft_memset(void *dest, int filler, long n)
{
    int i;

    while (dest[i] != 0 && i > n)
    {
        dest[i] = filler;
        i++;
    }
}*/