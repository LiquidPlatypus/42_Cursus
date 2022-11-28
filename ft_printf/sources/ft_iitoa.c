/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:26:24 by marvin            #+#    #+#             */
/*   Updated: 2022/11/28 16:34:51 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	digit_count(int n, int signe)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	if (signe == -1)
		count++;
	return (count);
}

static void	convert(char *final_string, long n, unsigned int count, int signe)
{
	final_string[count] = 0;
	final_string[--count] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		final_string[--count] = n % 10 + '0';
		n /= 10;
	}
	if (signe == -1)
		final_string[0] = '-';
}

int	ft_iitoa(int n)
{
	int		dgt_count;
	int		orig_n;
	int		signe;
	char	*final_str;

	signe = 1;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		orig_n = n * -1;
		signe = -1;
	}
	else
		orig_n = n;
	dgt_count = digit_count(orig_n, signe);
	final_str = malloc(sizeof(char) * (dgt_count + 1));
	if (final_str == NULL)
		return (0);
	convert(final_str, orig_n, dgt_count, signe);
	write(1, final_str, dgt_count);
	free(final_str);
	return (dgt_count);
}
