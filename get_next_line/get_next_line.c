/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:15 by lsinke            #+#    #+#             */
/*   Updated: 2022/12/27 09:58:35 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Checks if left contains a newline. If not, read BUFFER_SIZE bytes
 * and append them onto left. Repeat.
 *
 * Returns NULL if anything went wrong
 */
static char	*ft_read_until_nl(int fd, char *left)
{
	char	*buffer;
	ssize_t	byt_read;
	size_t	left_len;

	if (ft_find_nl(left))
		return (left);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	left_len = ft_sstrlen(left);
	buffer[0] = '\0';
	while (!ft_find_nl(buffer))
	{
		byt_read = read(fd, buffer, BUFFER_SIZE);
		if (byt_read <= 0)
			break ;
		buffer[byt_read] = '\0';
		left = ft_strjoin(left, buffer, left_len, byt_read);
		left_len += byt_read;
		if (!left)
			break ;
	}
	free(buffer);
	return (left);
}

/**
 * Return everything in left up to (and including) the first newline
 * If there is no newline, returns left and sets left_p to NULL
 * If there is a newline, allocate a new string and copy everything.
 */
static char	*ft_ft_get_line(char **left_p, char *left)
{
	char	*line;
	char	*newline_i;
	size_t	i;

	newline_i = ft_find_nl(left);
	if (!newline_i)
	{
		line = left;
		*left_p = NULL;
		return (line);
	}
	line = malloc((newline_i - left + 1 + 1) * sizeof(char));
	if (!line)
	{
		free(left);
		*left_p = NULL;
		return (NULL);
	}
	i = 0;
	while (left != newline_i)
		line[i++] = *left++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * Get everything after the first '\n' and put it in a new string.
 * Always frees left
 * If the newline was the last character in the string, return NULL
 */
static char	*ft_ft_get_left(char *left)
{
	char	*str;
	char	*newline_i;
	size_t	len;
	size_t	n;

	len = ft_sstrlen(left);
	newline_i = ft_find_nl(left);
	n = len - (newline_i - left);
	if (n != 1)
		str = malloc(n * sizeof(char));
	else
		str = NULL;
	if (str)
		while (n--)
			str[n] = newline_i[n + 1];
	free(left);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	left = ft_read_until_nl(fd, left);
	if (!left)
		return (NULL);
	line = ft_ft_get_line(&left, left);
	if (left != NULL)
		left = ft_ft_get_left(left);
	return (line);
}
