/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:47:38 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:43 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_params_search(va_list params, const char *input)
{
	if (*input == 'c')
		return (ft_char(va_arg(params, int)));
	if (*input == 's')
		return (ft_string(va_arg(params, char *)));
/*	if (*input == 'p')
		return (ft_pointer(va_arg(params, void *))); */
	if (*input == 'd' || *input == 'i')
		return (ft_int(va_arg(params, int)));
	if (*input == 'u')
		return (ft_uint(va_arg(params, unsigned int)));
	if (*input == 'x' || *input == 'X')
		return (ft_hexa(va_arg(params, int)));
	if (*input == '%')
		return (ft_percent());
	return (-1);
}
