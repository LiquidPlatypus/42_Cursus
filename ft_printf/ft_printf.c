/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/21 16:10:40 by tbournon         ###   ########.fr       */
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
	int			x;
	// char		*s;

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
			char_parsing(va_arg(param, ), *input);
	/*	if (*input == 'c')
		{
			x = va_arg(params, int);
			ft_putchar_fd(x, 1);
			break ;
		} */
	/* 	else if (*cur_arg == 's')
		{
			s = va_arg(params, char *);
			// !
			break ;
		} */
	/*	else if (*cur_arg == 'p')
		{
			// !
		} */
	/* 	else if (*cur_arg == 'd')
		{
			x = va_arg(params, int);
			if (x < 0)
			{
				x = -x;
				ft_putchar_fd('-');
			}
			// !
			break ;
		} */
	/*	else if (*cur_arg == 'i')
		{
			x = va_arg(params, int);
			if (x < 0)
			{
				x = -x;
				ft_putchar_fd('-');
			}
			// !
			break ;
		} */
	/* else if (*cur_arg == 'u')
		{
			// !
		} */
	/* 	else if (*cur_arg == 'x')
		{
			x = va_arg(params, unsigned int);
			// !
			break ;
		} */
	/* 	else if (*cur_arg == 'x')
		{
			x = va_arg(params, unsigned int);
			// !
			break ;
		} */
	/* 	else if (*cur_arg == 'o')
		{
			x = va_arg(params, unsigned int);
			// !
			break ;
		} */
	}
	va_end(params);
	return (0);
}


int main()
{
	char c = 'c';
	ft_printf("bonjour %c\n", c);

	return 0;
}