/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:04:40 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/17 16:41:40 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // !                                 
#include <stdio.h> // !                                 

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buffer;
	int		byt_readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byt_readed = 1;
	while (!ft_strchr(left_str, '\n') && byt_readed != 0)
	{
		byt_readed = read(fd, buffer, BUFFER_SIZE);
		if (byt_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byt_readed] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

/*
int main()
{
	int x;

	x = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(x));
	printf("%s", get_next_line(x));

	return (0);
}
*/