/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:17 by lsinke            #+#    #+#             */
/*   Updated: 2022/12/23 15:51:17 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len)
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

size_t	ft_sstrlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		++l;
	return (l);
}

char	*ft_find_nl(char *str)
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
