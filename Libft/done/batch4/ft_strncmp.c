#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

/*
int	main(void)
{
	char	test1[] = "ABe";
	char	test2[] = "BCD";
	char	test3[] = "123b";
	char	test4[] = "123a";
	char	test5[] = "wordS";
	char	test6[] = "wordY";

	printf("text1:%s text2:%s\n", test1, test2);
	printf("n = 0; return: %d (mine)\n", ft_strncmp(test1, test2, 0));
	printf("n = 0; return: %d (correct)\n", strncmp(test1, test2, 0));
	printf("text1:%s text2:%s\n", test3, test4);
	printf("n = 3; return: %d (mine)\n", ft_strncmp(test3, test4, 3));
	printf("n = 3; return: %d (correct)\n", strncmp(test3, test4, 3));
	printf("text1:%s text2:%s\n", test5, test6);
	printf("n = 4; return: %d (mine)\n", ft_strncmp(test5, test6, 4));
	printf("n = 4; return: %d (correct)\n", strncmp(test5, test6, 4));
	return (0);
}
*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	while (i + 1 < n && (s1[i] != '\0' || s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
