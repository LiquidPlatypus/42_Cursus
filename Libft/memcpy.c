/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:39:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 12:51:19 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int		x;
	unsigned char		*p;
	const unsigned char	*q;

	x = 0;
	p = dst;
	q = src;
	while (n > 0)
	{
		p[x] = q[x];
		x++;
		n--;
	}
	dst = p;
	src = q;
	return (dst);
}
