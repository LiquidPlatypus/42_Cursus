/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:47:38 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 14:06:32 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*ft_params_search(va_list params, const char *input, t_print *tab)
{
	int	count;

	count = 0;
	if (*input == 'c')
		count += ft_char(va_arg(params, int));
}
