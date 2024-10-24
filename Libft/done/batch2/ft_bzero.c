#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, int n);

/*
int	main(void)
{
	char	string1[] = "bom dia olá";
	char	string2[] = "bom dia olá";

	printf("%s (original)\n", string1);
	bzero(string1, 5);
	printf("%s (cleared)\n", string1);
	printf("%c (char 4)\n", string1[4]);
	printf("%c (char 5)\n", string1[5]);
	printf("%s (original)\n", string2);
	ft_bzero(string2, 5);
	printf("%s (cleared)\n", string2);
	printf("%c (char 4)\n", string2[4]);
	printf("%c (char 5)\n", string2[5]);
	return (0);
}
*/

void	ft_bzero(void *s, int n)
{
	int i;
	unsigned char *str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}