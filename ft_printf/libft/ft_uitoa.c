/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:54:46 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:49:16 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(unsigned int n)
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
	return (count);
}

static void	convert(char *final_string, long n, unsigned int count)
{
	final_string[count] = 0;
	final_string[--count] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		final_string[--count] = n % 10 + '0';
		n /= 10;
	}
}

int	ft_uitoa(unsigned int n)
{
	int		dgt_count;
	char	*final_str;

	dgt_count = digit_count(n);
	final_str = malloc(sizeof(char) * (dgt_count + 1));
	if (final_str == NULL)
		return (-1);
	convert(final_str, n, dgt_count);
	n = write(1, final_str, dgt_count);
	free(final_str);
	return (n);
}
