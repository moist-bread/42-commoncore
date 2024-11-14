/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:46:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/14 12:38:35 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*get_next_line(int fd);
void	*ft_buffzero(char *buff, size_t n);
char 	*ft_add_line_chunck(char *start, char *chunck);
void 	ft_buffrealign(char *buff);
int		ft_linelen(char *str);

/* int main(void)
{
	int fd;
	char *line;
	int i = 1;

	fd = open("text.txt", O_RDONLY);
	while(i <= 42)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		i++;
	}
} */

char *get_next_line(int fd)
{
	int len_read;
	static char buff[BUFFER_SIZE + 1];
	char *line;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (ft_buffzero(buff, BUFFER_SIZE));
	len_read = 1;
	//printf("entry buff: %s\n", buff);
	line = ft_add_line_chunck(NULL, buff);
	if (!line)
		return(NULL);
	ft_buffrealign(buff);
	while (len_read != 0 && line[ft_linelen(line) - 1] != '\n')
	{
		len_read = read(fd, buff, BUFFER_SIZE);
		//printf("read buff: %s\n", buff);
		line = ft_add_line_chunck(line, buff);
		if (!line)
			return(NULL);
		ft_buffrealign(buff);
	}
	return(line);
}

void	*ft_buffzero(char *buff, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
		buff[i++] = 0;
	return(NULL);
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
	i = -1;
	j = 0;
	while (start[++i])
		line[i] = start[i];
	while (chunck[j] && chunck[j - 1] != '\n')
	{
		line[i + j] = chunck[j];
		j++;
	}
	line[i + j] = 0;
	return (line);
}

void ft_buffrealign(char *buff)
{
	int i;
	int j;

	i= 0;
	while(buff[i] && buff[i] != '\n')
		i++;
	j = 0;
	if (buff[i] == '\n')
		while(buff[++i] && i < BUFFER_SIZE)
			buff[j++] = buff[i];
	ft_buffzero(&buff[j], BUFFER_SIZE - j);
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}
