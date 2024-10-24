#include <stdio.h>

char	*ft_strchr(char *str, int c);

/*
int	main(void)
{
	char	*string;
	int		character;

	string = "bom dia, flor do dia";
	character = 'a';
	printf("original: %s\npin: %c\nsearch result: %s\n", string, character,
		ft_strchr(string, character));
	return (0);
}
*/

char	*ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}

	if (c == 0)
		return (&str[i]);
	else
		return (0);
}