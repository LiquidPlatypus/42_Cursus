/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:21 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/22 15:31:23 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>			// ! 											
#include <stdio.h>			// !											

void	check_leaks(void);  // !											

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

// delete line find
char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of firts line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if EOL == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firtsline + 1
	line = ft_calloc((ft_sstrlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line== buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 1;
	// if no line return NULL
	if (!buffer[0])
		return (NULL);
	// go to EOL
	if (buffer[0] != '\n')
	{
		while (buffer[i] && buffer[i] != '\n')
			i++;
	}
	// malloc to EOL
	if (i < 2 || buffer[i] != '\n')
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if EOL is \0 or \n, replace EOL bu \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	int		byt_read;

	// malloc if res doesn't exist
	if (!str)
		str = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byt_read = 1;
	while (byt_read > 0)
	{
		// while not EOF read
		byt_read = read(fd, buffer, BUFFER_SIZE);
		if (byt_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		// 0 to end for leak
		buffer[byt_read] = 0;
		// join and free
		str = ft_free(str, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

/*
int main()
{
	int x;
	char *str;

	x = open("read_error.txt", O_RDONLY);

	while ((str = get_next_line(x)))
		printf("%s", str);
	printf("%s", str);

//	check_leaks();
	return (0);
}
*/