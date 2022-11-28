/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:15 by marvin            #+#    #+#             */
/*   Updated: 2022/11/28 11:12:33 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_uint(unsigned int nbr, t_print tab)
{
	unsigned int	count;

	return (count = ft_uitoa(nbr));
}
