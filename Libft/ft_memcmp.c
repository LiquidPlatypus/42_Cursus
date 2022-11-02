/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:48:28 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/02 09:56:13 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				index;
	unsigned char	*p;
	unsigned char	*q;

	index = 0;
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (p[index] && p[index] == q[index] && n > 0)
	{
		index++;
		n--;
	}
	if (n == 0)
		return (0);
	return (p[index] - q[index]);
}
