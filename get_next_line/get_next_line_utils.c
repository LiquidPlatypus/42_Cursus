/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:06:26 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/09 17:39:44 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int			index;

	index = 0;
	while (s[index] != (unsigned char)c && s[index] != '\0')
		index++;
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	x;
	char			*str;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str != NULL)
	{
		while (*s1 != '\0')
		{
			str[x] = *s1;
			x++;
			s1++;
		}
		while (*s2 != '\0')
		{
			str[x] = *s2;
			x++;
			s2++;
		}
		str[x] = '\0';
	}
	return (str);
}

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
