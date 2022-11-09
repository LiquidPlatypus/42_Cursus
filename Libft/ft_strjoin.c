/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:12:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/09 15:43:34 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
