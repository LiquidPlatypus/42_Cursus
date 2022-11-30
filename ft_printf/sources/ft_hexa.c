/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:05:15 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:48:56 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_hexa(char c, unsigned int nbr)
{
	char	*hexa;
	char	res[11];
	int		index;
	int		count;

	hexa = "0123456789ABCDEF";
	if (c == 'x')
		hexa = "0123456789abcdef";
	index = 0;
	while (nbr >= 16)
	{
		res[index++] = hexa[nbr % 16];
		nbr = nbr / 16;
	}
	res[index] = hexa[nbr];
	count = 0;
	while (index >= 0)
	{
		if (ft_putchar(res[index--]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
