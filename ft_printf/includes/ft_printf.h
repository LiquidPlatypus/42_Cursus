/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:28:33 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/28 10:54:02 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	int	width;
	int	total_len;
}	t_print;

// ft_char.c

int				ft_char(int c);

// ft_iitoa.c

int				ft_iitoa(int n);

// ft_int.c

int				ft_int(int nbr);

// ft_params_search.c

const char		*ft_params_search(va_list params,
					const char *input);

// ft_percent.c

int				ft_percent(void);

// ft_string.c

int				ft_string(char *input);

// ft_uint.c

unsigned int	ft_uint(unsigned int nbr);

#endif