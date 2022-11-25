/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 13:42:06 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strprcchr(const char *input)
{
	while (*input)
	{
		if (*input == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}

const char	ft_text_reader(t_print *tab, const char *input)
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

	if (!input)
		return (0);
	va_start(params, input);
	tab.width = 0;
	tab.total_len = 0;
	while (*input)
	{
		if (*input == '%')
			input = ft_params_search(params, input + 1, &tab);
		else
			input - ft_text_reader(&tab, input);
		if (!input)
		{
			write(1, "(null)", 6);
			va_end(params);
			return (tab.total_len);
		}
	}
	va_end(params);
	return (tab.total_len);
}
