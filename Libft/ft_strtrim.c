/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:15:53 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/11 14:01:49 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	begin_trim(char const *s1, char const *set)
{
	int	index;
	int	index2;
	int	count;

	index = 0;
	index2 = 0;
	count = 0;
	while (s1)
	{
		while (s1 && set)
		{
			if (s1[index] == set[index2])
			{
				while (s1[index++] == set[index2++])
					count++;
				index2 = 0;
			}
		}
	}
	return (count);
}

int	end_trim(char const *s1, char const *set)
{
	int	index;
	int	index2;
	int	count;

	index = ft_strlen(s1);
	index2 = ft_strlen(set);
	count = 0;
	while (s1[index] > 0)
	{
		while (s1[index] > 0 && set[index2] > 0)
		{
			if (s1[index] == set[index2])
			{
				while (s1[index--] == set[index2--])
					count++;
				index2 = ft_strlen(set);
			}
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		index2;
	int		final_len;
	char	*trimed;

	index = 0;
	index2 = begin_trim(s1, set);
	final_len = ft_strlen(s1) - (begin_trim(s1, set) - end_trim(s1, set));
	trimed = (char *)malloc(sizeof(char) * final_len);
	if (trimed == NULL)
		return (NULL);
	while (index++ < final_len)
	{
		trimed[index] = s1[index2];
		index2++;
	}
	return (trimed);
}
/*
int main()
{
	char str[] = "strstrbonjour astru revoirstr";

	printf("%s", ft_strtrim(str, "str"));

	return 0;
}
*/