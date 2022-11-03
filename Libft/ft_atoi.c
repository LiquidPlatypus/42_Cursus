/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:15:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/03 16:52:47 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespaces(const char *str, int *ptnr_x)
{
	int	x;
	int	compteur;

	x = 0;
	compteur = 1;
	while ((str[x] >= 9 && str[x] <= 12) || str[x] == 32)
		x++;
	if (str[x] && (str[x] == 43 || str[x] == 45))
	{
		if (str[x] == 45)
			compteur *= -1;
			x++;
	}
	*ptnr_x = x;
	return (compteur);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	result;
	int	signe;

	x = 0;
	result = 0;
	signe = whitespaces(str, &x);
	while (str[x] && str[x] >= 48 && str[x] <= 57)
	{
		result *= 10;
		result += str[x] - 48;
		x++;
	}
	result *= signe;
	return (result);
}
