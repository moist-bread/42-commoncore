#include <stdio.h>

// void	ft_toupper(unsigned int n, char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
int	main(void)
{
	char	*str;

	str = "Hallo Ebery Nyan";
	ft_striteri(str, ft_toupper);
	printf("%s", str);
}

void	ft_toupper(unsigned int n, char *str)
{
	if (str[n] >= 'A' && str[n] <= 'Z')
		printf("a");
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	while (s[i])
		f(i++, s);
}