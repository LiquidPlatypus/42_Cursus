/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:34 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:55 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// ! À CORRIGER -----------------------------------------------------------

int	substring_count(const char *s, char c)
{
	size_t	index;
	int		count;
	int		words;

	index = 0;
	count = 0;
	words = 1;
	while (s[index])
	{
		if (words && s[index] != c)
		{
			count++;
			words = 0;
		}
		if (s[index] == c)
			words = 1;
		index++;
	}
	return (count);
}

char	*word_length(const char *s, char c, int *len)
{
	int	taille;

	while (s[*len] == c)
		*len += 1;
	taille = *len;
	while (s[*len])
	{
		if (s[*len] == c)
			break ;
		*len += 1;
	}
	return (ft_substr(s, taille, *len - taille));
}

void	ft_check_free(char **s, int substrings)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	if (index == substrings)
		return ;
	index = 0;
	while (index <= substrings)
		free(s[index++]);
	// free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		len;
	int		substrings;
	char	**splited;

	index = 0;
	substrings = substring_count(s, c);
	if (!s)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (substrings + 1));
	if (splited == NULL)
		return (NULL);
	len = 0;
	while (index < substrings)
		splited[index++] = word_length(s, c, &len);
	splited[index] = NULL;
	ft_check_free(splited, substrings);
	return (splited);
}
