/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 11:37:37 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list		params;
	int		count;

	if (!input)
		return (0);
	va_start(params, input);
	
	va_end(params);
	return (count);
}

int	main(void)
{
	int	x;

	x = ft_printf("%c", '0');
	ft_printf("%c", '0');
	return (0);
}
