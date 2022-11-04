/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:15:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/04 12:15:37 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespaces(const char str)
{
	return ((str >= 8 && str <= 13) || str == 32);
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
