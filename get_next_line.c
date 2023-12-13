/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:07:23 by mbentahi          #+#    #+#             */
/*   Updated: 2023/12/13 10:21:17 by mbentahi         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_buffer_reader(char *str, int fd)
{
	ssize_t	read_bytes;
	char	*buffer;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = 0;
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(str), free(buffer), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}
char	*ft_readline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_line_remover(char *str)
{
	int		i;
	int		y;
	char	*holder;

	i = 0;
	if (!*str)
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	y = 0;
	while (str[y])
		y++;
	holder = malloc(sizeof(char) * (y - i + 1));
	if (!holder)
		return (free(str), NULL);
	y = 0;
	while (str[i])
	{
		holder[y] = str[i];
		i++;
		y++;
	}
	holder[y] = '\0';
	return (free(str), holder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_buffer_reader(str, fd);
	if (!str)
		return (NULL);
	line = ft_readline(str);
	str = ft_line_remover(str);
	if (!str)
		return (NULL);
	return (line);
}

int	main(void)
{
	int i;
	char *str;
	int fd;

	fd = open("tests", O_RDWR);
	str = get_next_line(fd);

	-printf("%s", str);
	free(str);

	return (0);
}