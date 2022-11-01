/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:53:07 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 13:06:44 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		x;
	unsigned char		*p;
	const unsigned char	*q;
	const unsigned char	*buffer;

	x = 0;
	p = dst;
	q = src;
	buffer = q;
	while (len > 0)
	{
		p[x] = buffer[x];
		x++;
		len--;
	}
	dst = p;
	src = q;
	return (dst);
}

int main()
{
	char dst[] = "bonjour";
	char src[] = "test";

	printf("%s\t%s\n", dst, src);

	ft_memmove(dst, src, 3);
	printf("%s", dst);

	return 0;
}