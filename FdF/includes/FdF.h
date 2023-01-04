/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:23 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/04 10:53:12 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct line_params
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x;
	float	y;
}		t_line;

# define WIDTH 1200
# define HEIGHT 1000

#endif