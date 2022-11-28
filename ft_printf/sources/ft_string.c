/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:38:14 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 11:06:23 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string(char *input)
{
	int	count;

	if (!input)
		count = ft_putstr("(null)");
	else
		count = ft_putstr(input);
	return (count);
}
