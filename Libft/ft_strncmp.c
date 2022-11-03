/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:17:47 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/03 14:00:02 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				x;
	unsigned char	*p;
	unsigned char	*q;

	x = 0;
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (p[x] && p[x] == q[x] && n > 0)
	{
		x++;
		n--;
	}
	if (n == 0)
		return (0);
	return (p[x] - q[x]);
}
