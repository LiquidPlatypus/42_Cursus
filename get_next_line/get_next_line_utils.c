/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:02:17 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/19 18:02:17 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		++l;
	return (l);
}

char	*find_newline(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
			++str;
		}
	}
	return (NULL);
}
