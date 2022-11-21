/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/21 11:08:41 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *input, ...)
{
	va_list		params;
	int			x;
	const char	*cur_arg;

	cur_arg = input;
	if (input == NULL)
		return (0);
	va_start(params, input);
	while (*cur_arg++ != '\0')
	{
		while (*cur_arg++ != '%')
			ft_putchar_fd(*cur_arg, 1);
		if (*cur_arg == 'c')
		{
			x = va_arg(params, int);
			ft_putchar_fd(x, 1);
			break ;
		}
		else if (*cur)
	}
	va_end(params);
	return (0);
}
