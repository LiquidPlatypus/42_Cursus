/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:59:39 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/08 15:49:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	src_length;
	unsigned int	dst_length;

	x = 0;
	y = 0;
	src_length = ft_strlen(src);
	dst_length = 0;
	if (dstsize == 0 || (dst == NULL && src == NULL))
		return (src_length + dstsize);
	x = 0;
	while (dst[y++])
		dst_length++;
	y = dst_length;
	if (dst_length < dstsize - 1 && dstsize > 0)
	{
		while (src[x] && dst_length + x < dstsize - 1)
			dst[y++] = src[x++];
		dst[y] = 0;
	}
	if (dst_length >= dstsize)
		dst_length = dstsize;
	return (dst_length + src_length);
}
