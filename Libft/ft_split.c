/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:34 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/10 15:26:58 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**splited;
	char	*buffer;
	int		c_count;
	int		index;
	int		split_index;

	c_count = 0;
	index = 0;
	split_index = 0;
	if (!s)
		return (NULL);
	while (s[index])				// ! ----------------------------------------------------------------------------
	{																		// !
		if (s[index] == c)													// TODO : peut-être en faire une focntion
			c_count++;														// !
		index++;															// !
	}								// ! ----------------------------------------------------------------------------
	splited = (char **)malloc(sizeof(char) * c_count);
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			buffer = (char *)malloc(sizeof(char) * index);
			ft_strlcpy(buffer, s, index);
			ft_strlcpy(splited[split_index], buffer, index);
		}
		index++;
	}
	return (splited);
}
