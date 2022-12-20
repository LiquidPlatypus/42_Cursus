/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:21 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/20 16:52:34 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>			// ! 											
#include <stdio.h>			// !											

void	check_leaks(void);  // !											

void	*ft_freestr(char *left_str, char *buffer)
{
	if (left_str != NULL)
	{
		free(left_str);
		return (NULL);
	}
	free(buffer);
	return (NULL);
}

static char	*ft_read_line(int fd, char *left_str, char *buff)
{
	int		byt_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(left_str, '\n'))
	{
		byt_read = read(fd, buff, BUFFER_SIZE);
		if (byt_read == -1)
		{
			free(buff);
			return (NULL);
		}
		else if (byt_read == 0)
		{
			ft_freestr(buff, left_str);
			return (NULL);
		}
		buff[byt_read] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	left_str = ft_read_line(fd, left_str, buffer);		// Doit lire la ligne
	if (!left_str)
		ft_freestr(left_str, buffer);	/* si fin du fichier, doit free la chaine au 1er appel si elle n'est pas vide, et au 2ème appel doit return NULL */
	line = ft_stack_line(left_str);				// stock la ligne jusqu'au \\n
	left_str = ft_left(left_str);				// stock ce qu'il reste après le \\n pour l'appel suivant
	return (line);
}

int main()
{
	int x;
	char *str;

	x = open("one_line_no_nl.txt", O_RDONLY);

	while ((str = get_next_line(x)))
		printf("%s", str);
	printf("%s", str);

	check_leaks();
	return (0);
}
