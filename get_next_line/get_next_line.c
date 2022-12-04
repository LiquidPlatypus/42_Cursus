/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:04:40 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/04 11:04:40 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // ! A ENLEVER -------------------------------------

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(&stash, &readed);
	// 2. extract from stash to line
	// 3. clean up stash
	return (line);
}

int	main(void)
{
	int	fd;
	int	*line;

	fd = open("test/simple", 0_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
