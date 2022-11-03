/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:09:01 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/03 11:48:41 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	size_src;

	x = 0;
	size_src = 0;
	while (src[x] != '\0')
	{
		size_src++;
		x++;
	}
	if (size_src > dstsize)
		return (0);
	x = 0;
	while (src[x] != '\0' && x < dstsize)
	{
		dst[x] = src[x];
		x++;
	}
	if (dstsize < size_src)
		dst[dstsize - 1] = '\0';
	return (size_src);
}

int main()
{
	char src[] = "bonjour";
	char dst[] = "test";
	int dstsize = 3;

	printf("%lu\n", ft_strlcpy(src, dst, dstsize));
	printf("%lu", strlcpy(src, dst, dstsize));

	return 0;
}