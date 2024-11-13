/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:46:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/13 17:51:03 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd);
void	*ft_buffzero(char *buff, size_t n);
int	ft_linelen(char *str);
char *ft_add_line_chunck(char *start, char *chunck);

int main(void)
{
	int fd;
	char *line;
	int i = 1;
	//printf("%s", ft_add_line_chunck(NULL, "chunck\nchunck"));
	fd = open("text.txt", O_RDONLY);
	while(i <= 2)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		i++;
	}
}

char *get_next_line(int fd)
{
	int i;
	int len_read;
	static char buff[BUFFER_SIZE + 1];
	char *line;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (ft_buffzero(buff, BUFFER_SIZE + 1));
	i = 0;
	len_read = 1;
	line = NULL;
	while (len_read != 0)
	{
		len_read = read(fd, buff, BUFFER_SIZE);
		line = ft_add_line_chunck(line, buff);
		i += ft_linelen(buff);
		if (line[i] == '\n')
			return(line);	
	}
	return(line);
}

char *ft_add_line_chunck(char *start, char *chunck)
{
	int		i;
	int		j;
	char	*line;

	if (!start)
	{
		start = malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	line = malloc((ft_linelen(start) + ft_linelen(chunck) + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (start[i])
	{
		line[i] = start[i];
		i++;
	}
	while (chunck[j] && chunck[j - 1] != '\n')
	{
		line[i + j] = chunck[j];
		j++;
	}
	line[i + j] = 0;
	return (line);
	
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}


/* char *get_next_line(int fd)
{
// WORKING BUT NOT WHAT IS NEEDED
	int i;
	int len_read;
	static char buff[BUFFER_SIZE + 1];
	char *buff2;
	
	len_read = 0;
	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		return (NULL);
	}
	while (1)
	{
		len_read += read(fd, &buff[i], 1);
		if (buff[i] == '\n' || buff[i] == '\0' || len_read != i + 1)
			break;
		i++;
	}
	if (len_read != i + 1)
		i--;
	if (buff[i] == '\n')
		buff[++i] = '\0';
	buff2 = malloc(i * sizeof(char));
	if (!buff2)
		return (NULL);
	while (i >= 0)
	{
		buff2[i] = buff[i];
		i--;
	}
	return (buff2);
} */

void	*ft_buffzero(char *buff, size_t n)
{
	size_t			i;

	if (!buff)
		return(NULL);
	i = 0;
	while (i < n)
		buff[i++] = 0;
	return(NULL);
}

/* char *get_next_line(int fd)
{
	int i;
	int len_read;
	static char buff[BUFFER_SIZE + 1];
	static char *buff2;
	
	len_read = 0;
	i = 0;
	while (1)
	{
		len_read += read(fd, &buff[i], 1);
		if (buff[i] == '\n' || buff[i] == '\0' || len_read != i + 1)
			break;
		i++;
	}
	if (len_read != i + 1)
		i--;
	if (buff[i] == '\n')
		buff[++i] = '\0';
	buff2 = malloc(i * sizeof(char));
	if (!buff2)
		return (NULL);
	while (i >= 0)
	{
		buff2[i] = buff[i];
		i--;
	}
	return (buff2);
} */

/* int main (void)
{

	int temp;
	int size;
	size = read (fd,buff, 10);
	buff[size] = '\0';
	printf("%s\n\n", buff);
	size = read (fd,buff, 10);
	buff[size] = '\0';
	printf("%s\n\n", buff);
	//close(fd);
	//fd = open("text.txt", O_RDONLY);
	//printf("%s\n\n", buff2);
	
} */