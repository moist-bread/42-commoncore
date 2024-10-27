#include <stdio.h>

char	*ft_strchr(const char *s, int c);

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

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *str;

	i = 0;
	str = (char *)s;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}

	if (c == 0)
		return (&str[i]);
	else
		return (0);
}