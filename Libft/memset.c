/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:10:47 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 12:31:53 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
