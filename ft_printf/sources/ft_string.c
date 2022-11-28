/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:38:14 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 11:02:36 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string(char *input)
{
	int	count;

	if (!input)
	{
		ft_putstr("(null)");
		count = 6;
	}
	else
		count = ft_putstr(input);
	return (count);
}
