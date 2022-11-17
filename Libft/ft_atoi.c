/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:15:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/17 14:31:48 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

static int	whitespaces(const char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == ' ');
}

int	ft_atoi(const char *str)
{
	int	x;
	int	result;
	int	signe;

	x = 0;
	result = 0;
	signe = 1;
	while (whitespaces(str[x]))
		x++;
	if (str[x] == 43 || str[x] == 45)
	{
		if (str[x] == 45)
			signe = -1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		result *= 10;
		result += str[x] - 48;
		x++;
	}
	result *= signe;
	return (result);
}
