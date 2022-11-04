/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:29:59 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/04 16:28:35 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*p;

	index = 0;
	p = (unsigned char *)s;
	while (index < n)
	{
		if (p[index] == (unsigned char)c)
			return (p + index);
		index++;
	}
	return (NULL);
}
