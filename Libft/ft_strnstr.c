/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:57:42 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/08 15:50:34 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (needle[index2] == '\0')
		return ((char *)haystack);
	if (len == 0 || (haystack == NULL && needle == NULL))
		return (NULL);
	while (haystack[index1] && index1 < len)
	{
		index2 = 0;
		while (haystack[index1 + index2] && needle[index2]
			&& index1 + index2 < len
			&& haystack[index1 + index2] == needle[index2])
			index2++;
		if (needle[index2] == '\0')
			return ((char *)haystack + index1);
		index1++;
	}
	return (NULL);
}
