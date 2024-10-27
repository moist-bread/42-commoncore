#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

/*
int	main(void)
{
	char	test1[] = "ABCDEF1234567";
	char	test2[] = "123";
	char	test3[] = "ABCDEF1234567";
	char	test4[] = "123";

	printf("text1: %s text2: %s\n", test1, test2);
	printf("return: %u \n", strlcpy(test1, test2, 13));
	printf("text1: %s text2: %s\n", test1, test2);
	printf("text1: %s text2: %s\n", test3, test4);
	printf("return: %lu \n", ft_strlcpy(test3, test4, 13));
	printf("text1: %s text2: %s\n", test3, test4);
	return (0);
}
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != 0)
	{
		dest[i] = 0;
		i++;
	}
	return (src_len);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}