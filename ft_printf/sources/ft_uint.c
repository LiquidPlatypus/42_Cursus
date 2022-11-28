/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:15 by marvin            #+#    #+#             */
/*   Updated: 2022/11/28 11:33:09 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_uint(unsigned int nbr, t_print *tab)
{
	return (tab->total_len = ft_uitoa(nbr));
}
