/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/23 17:42:35 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*number_parsing(int input)
{
	char	*returned_number;

	return (returned_number = ft_itoa((int)input));
}

char	char_parsing(void *input)
{
	char	returned_char;

	return (returned_char = (char)input);
}

char	*str_parsing(void *input)
{
	char	*returned_str;

	return (returned_str = (char *)input);
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int	ft_printf(const char *input, ...)
{
	va_list	params;
	size_t	count;
	// char	*str;

	count = 0;
	if (input == NULL)
		return (0);
	//  str = 
	va_start(params, input);
	while (*input != '\0')
	{
	/*	while (*input != '%')
		{
			if (*input == '\0')
				return (0);
			ft_putchar_fd(*input, 1);
			input++;
		} */
		input++;
		if (*input == 'c')
		{	
			count += ft_printchar(char_parsing(va_arg(params, char *)));
			input++;
		}
		if (*input == 's')
		{
			count += ft_printstr(str_parsing(va_arg(params, char *)));
			input++;
		}
	/*	if (*input == 'p')
		{
			// !
			input++;
		} */
		if (*input == 'd' || *input == 'i' || *input == 'u')
		{
			count += ft_printstr(number_parsing(va_arg(params, int)));
			input++;
		}
		/* if (*input == 'x' || *input == 'X')
		{
			
			input++;
		} */
	}
	va_end(params);
	// count = ft_strlen();
	return (count);
}

int	main(void)
{
	int	x;

	x = ft_printf("%cs%cs%c", 'c', 'b', 'a');
	ft_putnbr_fd(x, 1);
	ft_printchar('\n');
	ft_printf("%s", (char *) NULL);
	return (0);
}
