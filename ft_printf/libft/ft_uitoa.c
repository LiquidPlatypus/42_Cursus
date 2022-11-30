/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:54:46 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 10:59:38 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_uitoa(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_uitoa(n / 10);
		count += ft_uitoa(n % 10);
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	return (count);
}
