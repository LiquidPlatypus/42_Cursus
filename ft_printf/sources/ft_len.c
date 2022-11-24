/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:28:22 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/24 14:30:48 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len(int len, int sign, int is_zero)
{
	int	count;

	count = 0;
	while (len - sign > 0)
	{
		if (is_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len--;
		count++;
	}
	return (count);
}
