/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:12:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/09 14:49:58 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	s1_length;
	unsigned int	s2_length;
	char			*final_str;

	x = 0;
	y = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (s1_length + s2_length));
//	while (s1[x++])
//		;
	while (s1[x++])
		final_str[x] = s1[x];
	while (s2[y++])
	{
		final_str[x] = s2[y];
		x++;
	}
	return (final_str);
}
/*
int main()
{
	const char s1[] = "bonjour";
	const char s2[] = "test";

	printf("%s", ft_strjoin(s1, s2));

	return 0;
}
*/