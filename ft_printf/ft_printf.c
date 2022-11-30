/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:22:14 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		final_len;
	int		check;

	va_start(params, format);
	final_len = 0;
	while (*format)
	{
		check = 0;
		if (*format == '%')
		{
			check = ft_params_search(params, ++format);
			if (check == -1)
				return (-1);
			format++;
			final_len += check;
		}
		else
		{
			check = ft_putchar(*format++);
			if (check == -1)
				return (-1);
			final_len += check;
		}
	}
	va_end(params);
	return (final_len);
}
/*
int main()
{
	int x = ft_printf("%u", -1);
	puts("");
	printf("%d", x);
	return 0;
}
*/