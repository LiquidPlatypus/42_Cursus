/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:47:38 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 11:33:24 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*ft_params_search(va_list params, const char *input, t_print *tab)
{
	if (*input == 'c')
		tab->total_len += ft_char(va_arg(params, int), tab);
	if (*input == 's')
		tab->total_len += ft_string(va_arg(params, char *), tab);
/*	if (*input == 'p')
		tab->total_len += ft_pointer(va_arg(params, void *), tab); */
	if (*input == 'd' || *input == 'i')
		tab->total_len += ft_int(va_arg(params, int), tab);
	if (*input == 'u')
		tab->total_len += ft_uint(va_arg(params, unsigned int), tab);
/*	if (*input == 'x' || *input == 'X')
		tab->total_len += ft_hexa(va_arg(params, int), tab); */
	if (*input == '%')
		tab->total_len += ft_percent(tab);
	return (input);
}
