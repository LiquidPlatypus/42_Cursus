/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 09:32:39 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_sign(t_print *tab)
{
	tab->sign = 1;
	tab->is_zero = 0;
	return (tab);
}

t_print	*ft_total_len(va_list params, t_print *tab)
{
	tab->total_len = va_arg(params, int);
	if (tab->total_len < 0)
	{
		tab->sign = 1;
		tab->total_len *= -1;
	}
	return (tab);
}

int	ft_point(const char *str, int start,
			t_print *tab, va_list params)
{
	int	x;

	x = start;
	x++;
	tab->point = 0;
	while (ft_isdigit(str[x]))
		tab->point = (tab->point * 10) + (save[x++] - '0');
	return (x);
}