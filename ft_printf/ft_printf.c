/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/29 14:22:00 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>			// ! A ENLEVER

char	*ft_strprcchr(const char *input)
{
	while (*input)
	{
		if (*input == '%')
			return ((char *)input);
		input++;
	}
	if (!input)
		return ((char *)input);
	return (NULL);
}

const char	*ft_text_reader(t_print *tab, const char *input)
{
	char	*suiv;

	tab->width = 0;
	tab->total_len = 0;
	suiv = ft_strprcchr(input);
	if (suiv)
		tab->width = suiv - input;
	else
		tab->width = ft_strlen(input);
	write(1, input, tab->width);
	tab->total_len += tab->width;
	while (*input && *input != '%')
		++input;
	return (input);
}

int	ft_input_len(const char *input)
{
	int	index;

	index = 0;
	while (input[index] != '%' && input[index])
		index++;
	return (index);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	t_print	tab;
	int		final_len;

	if (!format)
		return (0);
	va_start(params, format);
	final_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			final_len += ft_params_search(params, ++format);
			format++;
		}
		else
		{
			final_len += ft_input_len(format);
			format = ft_text_reader(&tab, format);
		}
	}
	va_end(params);
	return (final_len);
}
/*
int	main(void)
{
	int	x = ft_printf("%X", -6000023);
	puts("");
	int	y = printf("%X", -6000023);
	puts("");


	printf("%d\n", x);
	printf("%d\n", y);

	return (0);
}
*/