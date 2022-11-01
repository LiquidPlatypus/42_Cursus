/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:59:39 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 15:17:04 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
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

int main()
{
	char src[] = "bonjour";
	char dest[] = "test";

	printf("%s\t%s\n", src, dest);

	ft_strlcat(dest, src, 0);
	printf("%s", dest);
	
	return 0;
}
