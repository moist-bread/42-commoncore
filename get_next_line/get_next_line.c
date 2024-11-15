/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:46:02 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/15 11:57:35 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			len_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (ft_buffzero(buff, BUFFER_SIZE));
	line = ft_add_line_chunck(NULL, buff);
	if (!line)
		return (NULL);
	ft_buffrealign(buff);
	len_read = 1;
	while (!(ft_withnewline(line)))
	{
		len_read = read(fd, buff, BUFFER_SIZE);
		if (len_read <= 0)
			break ;
		line = ft_add_line_chunck(line, buff);
		if (!line)
			return (NULL);
		ft_buffrealign(buff);
	}
	if (!line[0] || len_read < 0)
		return (ft_freeline(line));
	return (line);
}

void	*ft_buffzero(char *buff, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		buff[i++] = 0;
	return (NULL);
}

/* int main(void)
{
	char	*line;

	//terminal input get line
	write(1, "your input: ", 13);
	line = get_next_line(1);
	printf("line: %s", line);
	ft_freeline(line);
	return(0);
}
int	main(void)
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
		ft_freeline(line);
	}
	return(0);
} */