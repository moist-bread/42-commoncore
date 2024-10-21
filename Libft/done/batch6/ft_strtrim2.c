#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);
int		ft_strstr(char const *str, char const *to_find);
int		ft_strend(int i, char const *s1, char const *set);

int	main(void)
{
	char const	original[] = "macaaaacbmacbabomacahello";
	char const	ref[] = "maca";
	int			begin;

	begin = ft_strstr(original, ref);
	printf("%s (original)\n%s (ref)\n", original, ref);
	printf("%i (trim begin)\n", begin);
	printf("%i (trim end)\n", ft_strend(begin, original, ref));
	printf("%s (return)", ft_strtrim(original, ref));
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		n;
	int		j;
	char	*trimmed;

	i = ft_strstr(s1, set);
	n = ft_strend(i, s1, set);
	j = 0;
	trimmed = malloc((n - i + 2) * sizeof(char));
	if (trimmed == NULL)
		return (0);
	while (s1[i] != 0 && i <= n)
	{
		trimmed[j] = s1[i];
		j++;
		i++;
	}
	trimmed[j] = 0;
	return (trimmed);
}

int	ft_strstr(char const *str, char const *to_find)
{
	int	i;
	int	pin;

	pin = 0;
	if (to_find[0] == '\0')
		return (0);
	while (str[pin] != '\0')
	{
		if (str[pin] == to_find[0])
		{
			i = 0;
			while (str[pin + i] == to_find[i] && to_find[i] != '\0')
			{
				i++;
			}
			if (to_find[i] == '\0')
				return (pin + i);
		}
		pin++;
	}
	return (0);
}

int	ft_strend(int begin, char const *str, char const *to_find)
{
	int i;
	int pin;

	pin = begin;
	if (to_find[0] == '\0')
		return (0);
	while (str[pin] != '\0')
	{
		if (str[pin] == to_find[0])
		{
			i = 0;
			while (str[pin + i] == to_find[i] && to_find[i] != '\0')
			{
				i++;
			}
			if (to_find[i] == '\0')
				return (pin - 1);
		}
		pin++;
	}
	return (0);
}