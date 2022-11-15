/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:34 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/15 12:49:39 by tbournon         ###   ########.fr       */
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

int	word_length(const char *s, char c, int *len)
{
	int	taille;

	while (s[*len] == c)
		*len++;
	taille = *len;
	while (s[*len])
	{
		if (s[*len] == c)
			break ;
		*len++;
	}
	return (ft_substr(s, taille, *len - taille));
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
	while (substrings--)
	{
		splited[index] = word_length(s, c, &len);
		index++;
	}
	splited[index] = NULL;
	free((void *)splited);
	return (splited);
}
