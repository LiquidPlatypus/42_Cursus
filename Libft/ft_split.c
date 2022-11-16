/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:34 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/16 11:26:04 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free(void **array, size_t n)
{
	while (n)
		free(array[--n]);
	free(array);
	return (0);
}

size_t	ft_substrings_count(const char *s, char c)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = 0;
	while (s[index++])
	{
		while (s[index] != c && s[index])
			index++;
		len++;
		while (s[index] == c && s[index])
			index++;
	}
	return (len);
}

char	**ft_spliteur(const char *s, char c, char **res)
{
	size_t	len;
	size_t	index;
	size_t	y;

	index = 0;
	y = 0;
	while (s[y])
	{
		len = 0;
		while (s[y] != c && s[y] && ++y)
			len++;
		res[index] = malloc(len + 1);
		if (!res[index])
			return ((char **)ft_free((void **) res, index));
		ft_strlcpy(res[index++], &s[y - len], len + 1);
		while (s[y] == c && s[y])
			y++;
	}
	res[index] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	size_t	index;
	char	**splited;

	if (!s)
		return (0);
	index = 0;
	while (s[index] == c && s[index])
		index++;
	splited = (char **)malloc(sizeof(char *)
			* (ft_substrings_count(&s[index], c) + 1));
	if (!splited)
		return (0);
	return (ft_spliteur(&s[index], c, splited));
}
