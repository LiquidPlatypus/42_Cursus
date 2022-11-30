/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:05:15 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:34 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_hexa(char c, unsigned int nbr)
{
	char	*hexa;
	char	*hexaup;
	char	res[100];
	int		index;
	int		count;

	hexa = "0123456789abcdef";
	hexaup = "0123456789ABCDEF";
	index = 0;
	while (nbr >= 16)
	{
		if (c == 'x')
			res[index++] = hexa[nbr % 16];
		else
			res[index++] = hexaup[nbr % 16];
		nbr = nbr / 16;
	}
	if (c == 'x')
		res[index] = hexa[nbr];
	else
		res[index] = hexaup[nbr];
	count = index + 1;
	while (index >= 0)
		count = ft_putchar(res[index--]);
	return (count);
}
