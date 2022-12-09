/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:04:40 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/09 17:49:28 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // !    A ENLEVER ----------------------------------------------------
#include <stdio.h> // !    A ENLEVER ----------------------------------------------------

char	*get_next_line(int fd)
{
	char	line[BUFFER_SIZE + 1];
	// int		index;

	//index = BUFFER_SIZE;
	if (fd < 0)
		return (NULL);
	read(fd, line, BUFFER_SIZE);
	line[BUFFER_SIZE] = '\0';
	return (line);
}

int main()
{
	int x;

	x = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(x));

	return (0);
}