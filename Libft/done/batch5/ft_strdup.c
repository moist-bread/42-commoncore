// #include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);
int		ft_strlen(char *str);

/*
int	main(void)
{
		char    str[] = "bom dia flor do dia";

		printf("%s\n", ft_strdup(str));
		return (0);
}
*/

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(src) * sizeof(char));
	if (dup == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
