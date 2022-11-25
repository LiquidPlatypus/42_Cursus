/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:07:28 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 09:57:28 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printchar(char c, t_print tab)
{
	int	count;

	count = 0;
	if (tab.sign == 1)
		ft_putchar(c);
	count = ft_len(tab.total_len, 1, 0);
	if (tab.sign == 0)
		ft_putchar(c);
	return (count + 1);
}
