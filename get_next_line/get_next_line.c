/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:15 by lsinke            #+#    #+#             */
/*   Updated: 2022/12/23 12:36:35 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * Join s1 and s2, making a copy of s2 if s1 is null. Always free s1.
 *
 * Takes the lengths of s1 and s2 as additional args to improve performance
 *
 * @return NULL if malloc fails, otherwise a freshly malloced string
 */
static char	*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len)
{
	char	*str;
	size_t	idx;

	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	idx = 0;
	while (idx < s1_len)
	{
		str[idx] = s1[idx];
		++idx;
	}
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	if (s1)
		free(s1);
	return (str);
}

/**
 * Checks if leftover contains a newline. If not, read BUFFER_SIZE bytes
 * and append them onto leftover. Repeat.
 *
 * Returns NULL if anything went wrong
 */
static char	*read_until_newline(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	read_bytes;
	size_t	leftover_len;

	if (find_newline(leftover))
		return (leftover);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	leftover_len = ft_strlen(leftover);
	buffer[0] = '\0';
	while (!find_newline(buffer))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		leftover = ft_strjoin(leftover, buffer, leftover_len, read_bytes);
		leftover_len += read_bytes;
		if (!leftover)
			break ;
	}
	free(buffer);
	return (leftover);
}

/**
 * Return everything in leftover up to (and including) the first newline
 * If there is no newline, returns leftover and sets leftover_p to NULL
 * If there is a newline, allocate a new string and copy everything.
 */
static char	*get_line(char **leftover_p, char *leftover)
{
	char	*line;
	char	*newline_idx;
	size_t	i;

	newline_idx = find_newline(leftover);
	if (!newline_idx)
	{
		line = leftover;
		*leftover_p = NULL;
		return (line);
	}
	line = malloc((newline_idx - leftover + 1 + 1) * sizeof(char));
	if (!line)
	{
		free(leftover);
		*leftover_p = NULL;
		return (NULL);
	}
	i = 0;
	while (leftover != newline_idx)
		line[i++] = *leftover++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * Get everything after the first '\n' and put it in a new string.
 * Always frees leftover
 * If the newline was the last character in the string, return NULL
 */
static char	*get_leftover(char *leftover)
{
	char	*str;
	char	*newline_idx;
	size_t	len;
	size_t	n;

	len = ft_strlen(leftover);
	newline_idx = find_newline(leftover);
	n = len - (newline_idx - leftover);
	if (n != 1)
		str = malloc(n * sizeof(char));
	else
		str = NULL;
	if (str)
		while (n--)
			str[n] = newline_idx[n + 1];
	free(leftover);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	leftover = read_until_newline(fd, leftover);
	if (!leftover)
		return (NULL);
	line = get_line(&leftover, leftover);
	if (leftover != NULL)
		leftover = get_leftover(leftover);
	return (line);
}
