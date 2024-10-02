// #include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int ft_strlen(char *str);

/*
int     main(void)
{
        char    test1[10] = "ABC";
        char    test2[] = "DEFG";

        printf ("text1: %s text2: %s\n", test1, test2);
        printf ("return: %u \n", ft_strlcat(test1, test2, 10));
        return (0);
}
*/

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len;
    unsigned int src_len;

    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    if (size <= dest_len)
        return (size + src_len);
    return (dest_len + src_len);
}

unsigned int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}