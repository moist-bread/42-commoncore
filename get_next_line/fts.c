/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:36 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/11/15 11:56:37 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			break ;
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
			break ;
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
