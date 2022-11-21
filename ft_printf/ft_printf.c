/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:32 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_parsing(void *input, char c)
{
	char	*returned_string;
	char	returned_char;

	if (c == 'c')
		return (returned_char = input);
	else
		return (returned_string = &input);
}

int	ft_printf(const char *input, ...)
{
	va_list		params;

	if (input == NULL)
		return (0);
	va_start(params, input);
	while (*input != '\0')
	{
		while (*input != '%')
		{
			ft_putchar_fd(*input, 1);
			input++;
		}
		if (*input == 'c' || input == 's')
		{
			char_parsing(va_arg(param, char *), *input);
			input++;
		}
	}
	va_end(params);
	return (0);
}
