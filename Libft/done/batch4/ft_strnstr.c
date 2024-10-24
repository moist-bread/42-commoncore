#include <stdio.h>
#include <string.h>

char	*ft_strnstr(char *str, char *to_find, int n);

/*
int	main(void)
{
	char	text[] = "goodmorning and goodnight";
	char	pin[] = "dm";

	printf("text:'%s'\npin :'%s'\n", text, pin);
	printf("my return:%s \n", ft_strnstr(text, pin, 4));
	return (0);
}
*/

char	*ft_strnstr(char *str, char *to_find, int n)
{
	int i;
	int pin;

	pin = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[pin] != '\0' && pin < n)
	{
		if (str[pin] == to_find[0])
		{
			i = 0;
			while (str[pin + i] == to_find[i] && to_find[i] != '\0' && pin
				+ i < n)
			{
				i++;
			}
			if (to_find[i] == '\0')
				return (&str[pin]);
		}
		pin++;
	}
	return (0);
}