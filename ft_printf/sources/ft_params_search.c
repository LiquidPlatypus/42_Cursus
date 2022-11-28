/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:47:38 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 10:55:30 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*ft_params_search(va_list params, const char *input)
{
	int	count;

	count = 0;
	if (*input == 'c')
		count += ft_char(va_arg(params, int));
	if (*input == 's')
		count += ft_string(va_arg(params, char *));
/*	if (*input == 'p')
		count += ft_pointer(va_arg(params, void *)); */
	if (*input == 'd' || *input == 'i')
		count += ft_int(va_arg(params, int));
	if (*input == 'u')
		count += ft_uint(va_arg(params, unsigned int));
/*	if (*input == 'x' || *input == 'X')
		count += ft_hexa(va_arg(params, int)); */
	if (*input == '%')
		count += ft_percent();
	return (input);
}
