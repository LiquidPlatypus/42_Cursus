/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:28:33 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/25 09:19:13 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_print
{
	va_list	params;
	int		width;
	int		precision;
	int		zero_padding;
	int		point;
	int		dash;
	int		total_len;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
}	t_print;

int		ft_flags(int c);
int		ft_flags_parsing(const char *str, int x, t_print *tab, va_list params);
int		ft_isdigit(int c);
int		ft_printchar(char c, t_print *tab);
int		ft_printf(const char *input, ...);
int		ft_printint(int x, t_print *tab);
int		ft_printpercent(t_print *tab);
int		ft_printptr(unsigned long long x, t_print *tab);
int		ft_printstr(char *str, t_print *tab);
int		ft_printuint(unsigned int x, t_print *tab);
void	ft_putchar(char c);
int		ft_putstr(char *str, int point);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
int		ft_type(int c);
char	*ft_uitoa(unsigned int n);

#endif