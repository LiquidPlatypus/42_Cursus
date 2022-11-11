/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:54:46 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/11 11:14:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	digit_count(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		dgt_count;
	int		orig_n;
	char	*final_str;

	dgt_count = digit_count(n);
	orig_n = n;
	final_str = (char *)malloc(sizeof(char) * dgt_count + 1);
	while (dgt_count--)
	{
		if (n == 0)
			final_str[dgt_count] = '0';
		else
		{
			final_str[dgt_count] = (n % 10) + 48;
			n /= 10;
		}
	}
	dgt_count = digit_count(orig_n);
	final_str[dgt_count] = '\0';
	return (final_str);
}

int main()
{
	printf("%s", ft_itoa(0));

	return (0);
}
