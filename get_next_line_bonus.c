/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:05:11 by mbentahi          #+#    #+#             */
/*   Updated: 2023/12/16 15:04:20 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
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
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(str), NULL);
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
	line = malloc(i + 1);
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
	int		j;
	char	*holder;

	if (!*str)
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	holder = malloc(ft_strlen(str) - i + 1);
	if (!holder)
		return (free(str), NULL);
	j = 0;
	while (str[i])
	{
		holder[j] = str[i];
		i++;
		j++;
	}
	holder[j] = '\0';
	return (free(str), holder);
}

char	*get_next_line(int fd)
{
	static char	*str[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	str[fd] = ft_buffer_reader(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_readline(str[fd]);
	str[fd] = ft_line_remover(str[fd]);
	if (!str[fd])
		return (free(line), NULL);
	return (line);
}
// int	main(void)
// {
// 	char *str;
// 	int fd;
// 	int fd1;
// 	fd = open("get_next_line.c", O_RDONLY);
// 	fd1 = open("get_next_line.c", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		if (!str)
// 			break;
// 		// lseek(fd, 0, 0);
// 		str = get_next_line(fd1);
// 		printf("%s", str);
// 		free(str);
// 	}
// 	free(str);
// 	return (0);
// }