/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:15:53 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/11 15:21:09 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	begin_trim(char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (*s1 && ft_strchr(set, *s1))
	{
		count++;
		s1++;
	}
	return (count);
}

int	end_trim(char const *s1, char const *set)
{
	int	index;
	int	count;

	index = ft_strlen(s1);
	count = 0;
	while (index-- > 0 && ft_strchr(set, s1[index - 1]))
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		index2;
	int		final_len;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	index2 = begin_trim(s1, set);
	final_len = ft_strlen(s1);
	trimed = (char *)malloc(sizeof(char) * (final_len - 1) + 1);
	if (trimed == NULL)
		return (NULL);
	while (index2 < final_len)
	{
		trimed[index] = s1[index2];
		index2++;
		index++;
	}
	trimed[index] = '\0';
	return (trimed);
}