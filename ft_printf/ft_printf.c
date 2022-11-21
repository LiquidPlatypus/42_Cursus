/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/21 14:05:48 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *input, ...)
{
	va_list		params;
	int			x;
	char		*s;
	const char	*cur_arg;

	cur_arg = input;
	if (input == NULL)
		return (0);
	va_start(params, input);
	while (*cur_arg++ != '\0')
	{
		while (*cur_arg++ != '%')
			ft_putchar_fd(*cur_arg, 1);
	/*	if (*cur_arg == 'c')
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
	ft_printf("bonjour\n");

	return 0;
}