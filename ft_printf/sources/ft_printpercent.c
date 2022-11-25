/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:32:41 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 10:12:34 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printpercent(t_print tab)
{
	int	count;

	count = 0;
	if (tab.sign == 1)
		count += ft_putstr("%", 1);
	count += ft_len(tab.total_len, 1, tab.is_zero);
	if (tab.sign == 0)
		count += ft_putstr("%", 1);
	return (count);
}
