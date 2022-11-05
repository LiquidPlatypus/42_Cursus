/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:59:39 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/05 12:08:50 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	src_length;

	x = 0;
	y = 0;
	src_length = 0;
	while (src[x])
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

/* int main()
{
	char str[] = "the cake is a lie !\0I'm hidden lol\r\n";
	// char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	printf("%d\n", ft_strlcat(buff2, str, max));
	printf("%lu", strlcat(buff2, str, max));

	return 0;
} */