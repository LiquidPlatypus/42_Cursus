/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/22 15:56:10 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*number_parsing(int input)
{
	int	returned_number;

	returned_number = 0;
	return (ft_itoa((int)input));
}
/*
char	*char_parsing(void *input, char c)
{
	char	*returned_string;
	char	returned_char;

	if (c == 'c')
		return (returned_char = (char)input);
	else
		return (returned_string = &input);
}
*/
int	ft_printf(const char *input, ...)
{
	va_list	params;

	if (input == NULL)
		return (0);
	va_start(params, input);
	while (*input != '\0')
	{
		while (*input != '%')
		{
			if (*input == '\0')
				return (0);
			ft_putchar_fd(*input, 1);
			input++;
		}
		input++;
		/*	if (*input == 'c' || *input == 's')
			{
				char_parsing(va_arg(params, char *), *input);
				input++;
			} */
		if (*input++ == 'd' || *input++ == 'i')
			ft_putstr_fd(number_parsing(va_arg(params, int)), 1);
	}
	va_end(params);
	return (0);
}

int	main(void)
{
	ft_printf("bonjour %d\n", 18);
	return (0);
}
