/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 10:16:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_print	ft_initializer(void)
{
	t_print	tab;

	tab.width = 0;
	tab.precision = 0;
	tab.zero_padding = 0;
	tab.point = 0;
	tab.sign = 0;
	tab.total_len = 0;
	tab.is_zero = 0;
	tab.dash = 0;
	tab.percent = 0;
	tab.space = 0;
	return (tab);
}

static int	ft_flags_pars(const char *str, int x, t_print tab)
{
	while (str[x])
	{
		if (!ft_isdigit(str[x]) && !ft_type(str[x]) && !ft_flags(str[x]))
			break ;
		if (str[x] == '0' && tab.total_len == 0 && tab.sign == 0)
			tab.is_zero = 1;
		if (str[x] == '.')
			x = ft_point(str, x, tab);
		if (str[x] == '-')
			tab = ft_sign(tab);
		x++;
	}
	return (x);
}

static int	ft_treatment(const char *str, va_list params)
{
	int		x;
	int		count;
	t_print	tab;

	x = 0;
	count = 0;
	while (1)
	{
		tab = ft_initializer();
		if (!str)
			break ;
		else if (str[x] == '%' && str[x + 1])
		{
			x = ft_flags_pars(str, ++x, tab);
			if (ft_type(str[x]))
				count += ft_choose(str[x], tab, params);
			else if (str[x])
				count += ft_printchar(str[x], tab);
		}
		else if (str[x] != '%')
			count += ft_printchar(str[x], tab);
		x++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list		params;
	size_t		count;
	const char	*str;

	count = 0;
	str = ft_strdup(input);
	va_start(params, input);
	count = ft_treatment(str, params);
	va_end(params);
	free((char *)str);
	return (count);
}

int	main(void)
{
	int	x;

	x = ft_printf("%cs%cs%c", 'c', 'b', 'a');
	ft_putnbr_fd(x, 1);
	ft_putchar('\n');
	ft_printf("%s", (char *) NULL);
	return (0);
}
