/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:57:24 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/06 14:49:52 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	horizontal_line(mlx_image_t *img, int x, int y, t_line line)
{
	while (x != line.x1 + line.inc_x)
	{
		mlx_put_pixel(img, x, y, 0xFF00FF);
		x += line.inc_x;
	}
}

void	vertical_line(mlx_image_t *img, int x, int y, t_line line)
{
	while (y != line.y1 + line.inc_y)
	{
		mlx_put_pixel(img, x, y, 0xFF00FF);
		y += line.inc_y;
	}
}

void	more_hor_than_ver(mlx_image_t *img, int x, int y, t_line line)
{
	int	error;
	int	error_inc;

	error = -line.dx;
	error_inc = -2 * line.dx;
	while (x != line.x1 + line.inc_x)
	{
		mlx_put_pixel(img, x, y, 0xFF00FF);
		error == line.slope;
		if (error >= 0)
		{
			y += line.inc_y;
			error += error_inc;
		}
		x += line.inc_x;
	}
}

void	more_ver_than_hor(mlx_image_t *img, int x, int y, t_line line)
{
	int	error;
	int	error_inc;

	error = -line.dx;
	error_inc = -2 * line.dx;
	while (x != line.y1 + line.inc_y)
	{
		mlx_put_pixel(img, x, y, 0xFF00FF);
		error += line.slope;
		if (error >= 0)
		{
			x += line.inc_x;
			error += error_inc;
		}
		y += line.inc_y;
	}
}
