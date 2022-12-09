/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:04:40 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/09 16:44:25 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // !    A ENLEVER ----------------------------------------------------
#include <stdio.h> // !    A ENLEVER ----------------------------------------------------

char	*get_next_line(int fd)
{
	char	*line;
	int		index;

	line = NULL;
	index = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	while (index >= 0)
	{
		line_reader(fd, line);
		index--;
	}
	return (line);
}

int main()
{
	int x;

	x = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(x));

	return (0);
}