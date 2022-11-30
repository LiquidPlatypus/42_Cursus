/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:47:38 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:08:16 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_params_search(va_list params, const char *input)
{
	if (*input == 'c')
		return (ft_char(va_arg(params, int)));
	if (*input == 's')
		return (ft_string(va_arg(params, char *)));
	if (*input == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_pointer(va_arg(params, unsigned long)) + 2);
	}
	if (*input == 'd' || *input == 'i')
		return (ft_iitoa(va_arg(params, int)));
	if (*input == 'u')
		return (ft_uitoa(va_arg(params, unsigned int)));
	if (*input == 'x' || *input == 'X')
		return (ft_hexa(*input, va_arg(params, int)));
	if (*input == '%')
		return (ft_percent());
	return (-1);
}
