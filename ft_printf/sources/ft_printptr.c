/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:57:21 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:38 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_minus(char *str, t_print *tab)
{
	int	count;

	count = 0;
	if (tab->point >= 0)
	{
		count += ft_len(tab->point, ft_strlen(str), 0);
		count += ft_putstr(str, tab->point);
	}
	else
		count += ft_putstr(str, ft_strlen(str));
}

int	ft_printptr(unsigned long long x, t_print *tab)
{

}
