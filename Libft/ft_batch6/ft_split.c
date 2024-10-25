#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
int		ft_seglen(char const *str, char c);
int		ft_segcount(char const *str, char c);

int	main(void)
{
	int		i;
	char	chara;
	char	**result;
	int		count;

	char sentence[] = "Lorem ipsuuum dolor sit amet,\
		consectetur adipiscing elit ";
	i = 0;
	chara = 'u';
	result = ft_split(sentence, chara);
	count = ft_segcount(sentence, chara);
	printf("%i\n", count);
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	int		segcount;
	char	**split;

	i = 0;
	j = 0;
	segcount = ft_segcount(s, c);
	split = malloc((segcount + 1) * sizeof(char *));
	if (split == NULL)
		return (0);
	while (i < segcount)
	{
		while (s[j] == c)
			j++;
		split[i] = malloc((ft_seglen(&s[j], c) + 1) * sizeof(char));
		if (split[i] == NULL)
			return (0);
		n = 0;
		while (s[j] != 0 && s[j] != c)
		{
			split[i][n] = s[j];
			n++;
			j++;
		}
		split[i][n] = 0;
		i++;
	}
	split[i] = 0;
	return (split);
}

int	ft_seglen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	ft_segcount(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}