/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:34 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/11 09:54:12 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ! À CORRIGER -----------------------------------------------------------

int	substring_count(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	char	*str;
	char	**splited;

	x = 0;
	y = 0;
	z = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	splited = (char **)malloc(sizeof(substring_count));
	while (s[x] != '\0')
	{
		if (str[x] == c)
		{
			str[y] = '\0';
			splited[z] = malloc(sizeof(str));
			ft_strlcpy(splited[z], str, sizeof(str));
			y = 0;
			z++;
			ft_memset((void *)str, 0, sizeof(s));
		}
		else
			str[y++] = s[x];
		x++;
	}
	return (splited);
}
