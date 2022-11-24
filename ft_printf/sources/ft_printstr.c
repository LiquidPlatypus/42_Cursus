/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:52 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/24 11:43:39 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printstr(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (len = ft_strlen(s));
	}
	return (0);
}
