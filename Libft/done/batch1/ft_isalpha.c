#include <stdio.h>


int	ft_isalpha(int c);

/*
int	main(void)
{

	printf("return: %d \n", ft_isalpha('A'));
	printf("return: %d \n", ft_isalpha('?'));
	printf("return: %d \n", ft_isalpha('a'));
	printf("return: %d \n", ft_isalpha('1'));
	return (0);
}
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
