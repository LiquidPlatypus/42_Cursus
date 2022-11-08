/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:59:39 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/08 14:43:00 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	src_length;
	unsigned int	dst_lenght;

	x = 0;
	y = 0;
	src_length = 0;
	dst_lenght = 0;
	while (src[x++])
		src_length++;
	x = 0;
	while (dst[y++])
		dst_lenght++;
	y = dst_lenght;
	if (dst_lenght < dstsize - 1 && dstsize > 0)
	{
		while (src[x] && dst_lenght + x < dstsize - 1)
			dst[y++] = src[x++];
		dst[y] = 0;
	}
	if (dst_lenght >= dstsize)
		dst_lenght = dstsize;
	return (dst_lenght + src_length);
}
