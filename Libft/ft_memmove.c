/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:53:07 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/04 15:14:08 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/*int main()
{
	char src[] = "lorem ipum dolor sit a";
	char dst[40];

	printf("%s\n", ft_memmove(dst, src, 8));
	printf("%s", memmove(dst, src, 8));

	return 0;
} */