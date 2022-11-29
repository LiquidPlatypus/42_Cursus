/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:23:31 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/29 14:28:12 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long	ft_pointer(unsigned long nbr)
{
	char	*hexaup;
	char	res[100];
	int		index;
	int		count;

	hexaup = "0123456789ABCDEF";
	index = 0;
	while (nbr >= 16)
	{
		res[index++] = hexaup[nbr % 16];
		nbr = nbr / 16;
	}
	res[index] = hexaup[nbr];
	count = index + 1;
	while (index >= 0)
		ft_putchar(res[index--]);
	return (count);
}
