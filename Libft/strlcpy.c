/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:09:01 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 13:58:02 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	size_src;

	x = 0;
	size_src = ft_strlen(src);
	while (src[x] != '\0' && x < dstsize)
	{
		dst[x] = src[x];
		x++;
	}
	if (dstsize < size_src)
		dst[dstsize - 1] = '\0';
	return (size_src);
}
