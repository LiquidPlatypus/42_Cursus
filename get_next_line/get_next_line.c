/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:04:40 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/13 16:40:53 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // ! A ENLVER -----------------------------------------
#include <stdio.h> // ! A ENLVER -----------------------------------------

static char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	int		len;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = 1;
	while (!ft_strchr(line, '\n') && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*ft_get_suiv_line(char *line)
{
	int		index;
	char	*str;

	index = 0;
	if (!line[index])
		return (NULL);
	while (line[index] && line[index] != '\n')
		index++;
	str = (char *)malloc(index + 2);
	if (!str)
		return (NULL);
	index = 0;
	while (line[index] && line[index] != '\n')
	{
		str[index] = line[index];
		index++;
	}
	if (line[index] == '\n')
	{
		str[index] = line[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

static char	*ft_new_line(char *line)
{
	int		index;
	int		index2;
	char	*str;

	index = 0;
	while (line[index] && line[index] != '\n')
		index++;
	if (!line[index])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - index + 1));
	if (!str)
		return (NULL);
	index++;
	index2 = 0;
	while (line[index])
		str[index2++] = line[index++];
	str[index2] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_line(fd, line);
	if (!line)
		return (NULL);
	next_line = ft_get_suiv_line(line);
	line = ft_new_line(line);
	return (next_line);
}

/*
int main()
{
	int x;

	x = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(x));

	return (0);
}
*/