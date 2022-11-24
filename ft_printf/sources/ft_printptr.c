/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:57:21 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/24 17:09:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// ! À FINIR -----------

static int	ft_minus(char *ptr, t_print *tab)
{
	int	count;

	count = 0;
	count += ft_putstr("0x", 2);
	if (tab->point >= 0)
	{
		count += ft_len(tab->point, ft_strlen(ptr), 1);
		count += ft_putstr(ptr, tab->point);
	}
	else
		count += ft_putstr(ptr, ft_strlen(ptr));
	return (count);
}

int	ft_printptr(unsigned long long x, t_print *tab)
{
	int		count;
	char	*ptr;

	count = 0;
	if (x == 0 && tab->point == 0)
	{
		count += ft_putstr("0x", 2);
		return (count += ft_len(tab->total_len, 0, 1));
	}
	ptr = 
}
