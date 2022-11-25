/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:40:42 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 10:15:42 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_choose(int c, t_print tab, va_list params)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_printchar(va_arg(params, int), tab);
	else if (c == 's')
		count = ft_printstr(va_arg(params, char *), tab);
/*	else if (c == 'p')
		count = */
	else if (c == 'd' || c == 'i')
		count += ft_printint(va_arg(params, int));
	else if (c == 'u')
		count += ft_printuint(va_arg(params, unsigned int));
/*	else if (c == 'x')
		count += 
	else if (c == 'X')
		count += */
	else if (c == '%')
		count += ft_printpercent(tab);
	return (count);
}
