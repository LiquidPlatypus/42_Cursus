/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:15:53 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/11 15:11:59 by tbournon         ###   ########.fr       */
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
	int		start;
	int		final_len;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	start = begin_trim(s1, set);
	final_len = (ft_strlen(s1) + 1) - (start + end_trim(s1, set));
	trimed = (char *)malloc(sizeof(char) * final_len + 1);
	if (trimed == NULL)
		return (NULL);
	ft_strlcpy(trimed, s1 + start, final_len + 1);
	return (trimed);
}
/*
int main()
{
	char str[] = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";

	printf("%s", ft_strtrim(str, " \n\t"));

	return 0;
}
*/