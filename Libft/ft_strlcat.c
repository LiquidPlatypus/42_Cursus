/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:59:39 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/02 15:09:47 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	src_length;

	x = 0;
	y = 0;
	src_length = 0;
	while (src[x] != '\0')
	{
		src_length++;
		x++;
	}
	x = 0;
	while (*dst && dstsize > 0)
	{
		dst++;
		x++;
		dstsize--;
	}
	while (*src && (dstsize - 1) > 1)
		*dst++ = *src++;
	if (dstsize == 1 || *src == 0)
		*dst = '\0';
	return (src_length + x);
}
