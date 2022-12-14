/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:23 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/11 11:10:20 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct line_params
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	float	slope;
	int		dx;
	int		dy;
	int		inc_x;
	int		inc_y;
}		t_line;

// draw_line.c
void	horizontal_line(mlx_image_t *img, int x, int y, t_line line);
void	vertical_line(mlx_image_t *img, int x, int y, t_line line);
void	more_hor_than_ver(mlx_image_t *img, int x, int y, t_line line);
void	more_ver_than_hor(mlx_image_t *img, int x, int y, t_line line);

// utils.c
int		absolute_value(int nbr);
int		signe(int nbr);
t_line	initializer(mlx_t *mlx);

# define WIDTH 1200
# define HEIGHT 1000

#endif