/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:52 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 10:14:43 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_minus(char *str, t_print tab)
{
	int	count;

	count = 0;
	if (tab.point >= 0)
	{
		count += ft_len(tab.point, ft_strlen(str), 0);
		count += ft_putstr(str, tab.point);
	}
	else
		count += ft_putstr(str, ft_strlen(str));
	return (count);
}

int	ft_printstr(char *str, t_print tab)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (tab.point >= 0 && tab.point > ft_strlen(str))
		tab.point = ft_strlen(str);
	if (tab.sign == 1)
		count += ft_minus(str, tab);
	if (tab.point >= 0)
		count += ft_len(tab.total_len, tab.sign, tab.is_zero);
	else
		count += ft_len(tab.total_len, ft_strlen(str), 0);
	if (tab.sign == 0)
		count += ft_minus(str, tab);
	return (0);
}
