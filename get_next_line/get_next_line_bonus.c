/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:15 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/26 14:29:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h> // !                                                         
#include <fcntl.h> // !                                                         

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
	size_t	i;

	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		++i;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

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
static char	*ft_get_line(char **left_p, char *left)
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
static char	*ft_get_left(char *left)
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
	static t_buf_list	*buf_list = NULL;
	t_buf_list			*cur_lst_list;
	char				*line;

	if (fd < 0)
		return (NULL);
	cur_lst_list = ft_find_or_create_lst(&buf_list, fd);
	if (!cur_lst_list)
		return (NULL);
	cur_lst_list->left = ft_read_until_nl(fd, cur_lst_list->left);
	if (cur_lst_list->left != NULL)
		line = ft_get_line(&cur_lst_list->left, cur_lst_list->left);
	else
		line = NULL;
	if (cur_lst_list->left != NULL)
		cur_lst_list->left = ft_get_left(cur_lst_list->left);
	if (cur_lst_list->left == NULL)
		ft_remove_lst_item(&buf_list, cur_lst_list);
	return (line);
}

/*
int main()
{
	int x = open("test.txt", O_RDONLY);
	int y = open("test2.txt", O_RDONLY);
	char *str;

	printf("%s", (str = get_next_line(x)));
	printf("%s", (str = get_next_line(y)));
	printf("%s", (str = get_next_line(y)));
	printf("%s", (str = get_next_line(x)));
	printf("%s", (str = get_next_line(y)));

	return 0;
}
*/