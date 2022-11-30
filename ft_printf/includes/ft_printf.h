/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:28:33 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/30 15:31:23 by tbournon         ###   ########.fr       */
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

// ft_hexa.c

unsigned int	ft_hexa(char c, unsigned int nbr);

// ft_iitoa.c

int				ft_iitoa(int n);

// ft_uitoa.c

int				ft_uitoa(unsigned int n);

// ft_params_search.c

int				ft_params_search(va_list params,
					const char *input);

// ft_percent.c

int				ft_percent(void);

// ft_pointer.c

unsigned long	ft_pointer(unsigned long ptr);

// ft_printf.c

int				ft_printf(const char *format, ...);

// ft_string.c

int				ft_string(char *input);

#endif