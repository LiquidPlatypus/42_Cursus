/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 13:27:26 by tbournon         ###   ########.fr       */
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
		if (check == -1)
			break ;
		if (*format == '%')
		{
			final_len += ft_params_search(params, ++format);
			format++;
		}
		else
			final_len += ft_putchar(*format++);
	}
	va_end(params);
	return (final_len);
}
