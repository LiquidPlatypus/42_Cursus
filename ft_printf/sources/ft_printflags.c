/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 10:06:50 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	ft_sign(t_print tab)
{
	tab.sign = 1;
	tab.is_zero = 0;
	return (tab);
}

int	ft_point(const char *str, int start, t_print tab)
{
	int	x;

	x = start;
	x++;
	tab.point = 0;
	while (ft_isdigit(str[x]))
		tab.point = (tab.point * 10) + (str[x++] - '0');
	return (x);
}