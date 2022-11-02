/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:29:59 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/02 09:45:49 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		index;
	const unsigned char	*p;

	index = 0;
	p = s;
	while (p[index] != c && p[index] != '\0' && n > 0)
		index++;
	if (p[index] == c)
		return ((void *)&p[index]);
	else
		return (NULL);
}
