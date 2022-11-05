/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:53:07 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/05 13:11:49 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		x;
	unsigned char		*p;
	const unsigned char	*q;

	x = 0;
	p = dst;
	q = src;
	if ((p == NULL && q == NULL) && len >= 0)
		return (p);
	if (p > q)
	{
		while (len-- > 0)
			p[len] = q[len];
	}
	else
	{
		while (len-- > 0)
		{
			p[x] = q[x];
			x++;
		}
	}
	return ((void *) p);
}
