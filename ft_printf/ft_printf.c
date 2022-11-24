/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:13:00 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/24 17:39:15 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

// ! QUASI TOUT À CHANGER LOL

static t_print	*ft_initializer(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero_padding = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->total_len = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percent = 0;
	tab->space = 0;
	return (tab);
}

static int	ft_which_format(t_print *tab, const char *input, int x)
{
	while (ft_isformat(input[x]) != 1)
	{
		if (input[x] == '.')
			tab->point = 1;
		if (input[x] == '-')
			tab->dash = 1;
		if (input[x] == '0')
			tab->is_zero = 1;
		x++;
	}

}

int	ft_printf(const char *input, ...)
{
	va_list	params;
	int		x;
	size_t	count;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initializer(tab->params);
	va_start(tab->params, input);
	x = -1;
	count = 0;
	while (input[++x])
	{
		if (input[x] == '%')
			x = ft_which_format(tab, input, x + 1);
		else
			count += write(1, &input[x], 1);
	}
	va_end(params);
	count += tab->total_len;
	free (tab);
	return (count);
}
/*
int	main(void)
{
	int	x;

	x = ft_printf("%cs%cs%c", 'c', 'b', 'a');
	ft_putnbr_fd(x, 1);
	ft_printchar('\n');
	ft_printf("%s", (char *) NULL);
	return (0);
}
*/