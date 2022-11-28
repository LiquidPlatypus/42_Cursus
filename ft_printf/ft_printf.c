/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 13:25:24 by tbournon         ###   ########.fr       */
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

int	ft_printf(const char *input, ...)
{
	va_list	params;
	t_print	tab;
	const char	*str;
	int x;

	str = input;
	if (!input)
		return (0);
	va_start(params, input);
	tab.width = 0;
	tab.total_len = 0;
	x = 0;
	while (*input)
	{
		if (*input == '%')
			x = ft_params_search(params, ++input);
		input++;
//		else
//			input = ft_text_reader(&tab, input);
	}
	va_end(params);
	puts("");
	printf("%s || %d\n", str, x);
	return (x);
}

int	main(void)
{
	int	x = ft_printf("%d", 42);
	puts("");
	int	y = printf("%d", 42);
	puts("");

	printf("%d\n", x);
	printf("%d\n", y);

	return (0);
}
