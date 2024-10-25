#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);
int		ft_trimbegin(char const *s1, char const *set);
int		ft_trimend(char const *s1, char const *set);

int main(void)
{
	char const	original[] = "aaaaaaaaaaaaaaabbbolaboababababababababbabaaaabbbaa";
	char const	ref[] = "ab";

	printf("%s (original)\n%s (ref)\n", original, ref);
	printf("%i (trim begin)\n", ft_trimbegin(original, ref));
	printf("%i (trim end)\n", ft_trimend(original, ref));
	printf("%s (return)", ft_strtrim(original, ref));
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		n;
	int		j;
	char	*trimmed;

	i = ft_trimbegin(s1, set);
	n = ft_trimend(s1, set);
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

int	ft_trimbegin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != 0)
			j++;
		if (s1[i] == set[j])
			i++;
		else
			return (i);
	}
	return (0);
}

int	ft_trimend(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != 0)
		i++;
	i--;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != 0)
			j++;
		if (s1[i] == set[j])
			i--;
		else
			return (i);
	}
	return (0);
}
