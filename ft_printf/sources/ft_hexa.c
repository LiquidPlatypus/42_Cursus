/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:05:15 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 18:11:30 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa(unsigned int nbr)
{
	char	*hexa;
	int		*res;
	int		index;
	int		count;

	while (nbr >= 16)
	{
		res[index] = hexa[nbr % 16];
		nbr = nbr / 16;
		index++;
	}
	res[index] = hexa[nbr];
	count = index;
	while (index >= 0)
	{
		ft_putchar(res[index]);
		index--;
	}
	return (count);
}
