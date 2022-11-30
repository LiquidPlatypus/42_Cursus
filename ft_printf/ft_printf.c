/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:57:32 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		final_len;
	int		check;

	va_start(params, format);
	final_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_params_search(params, ++format);
			if (check == -1)
				return (-1);
			format++;
		}
		else
		{
			check = ft_putchar(*format++);
			if (check == -1)
				return (-1);
		}
		final_len += check;
	}
	va_end(params);
	return (final_len);
}
