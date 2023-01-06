/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/06 13:41:39 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <stdlib.h> // !                                                
#include <stdio.h> // !                                                 
#include <unistd.h> // !                                                

int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	signe(int nbr)
{
	if (nbr < 0)
		return (-1);
	else if (nbr > 0)
		return (1);
	else
		return (0);
}

static void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

static void	line(mlx_image_t *img)
{
	t_line	line;
	int		x;
	int		y;
	int		error;
	int		error_inc;

	line.x0 = 150;
	line.y0 = 300;
	line.x1 = 1165;
	line.y1 = 750;
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	line.inc_x = signe(line.dx);
	line.inc_y = signe(line.dy);
	line.slope = 2 * line.dy;
	line.dx = absolute_value(line.dx);
	line.dy = absolute_value(line.dy);
	x = line.x0;
	y = line.y0;
	error = -line.dx;
	error_inc = -2 * line.dx;
	if (line.dy == 0)	// horizontal line
	{
		while (x != line.x1 + line.inc_x)
		{
			mlx_put_pixel(img, x, y, 0xFF00FF);
			x += line.inc_x;
		}
	}
	else if (line.dx == 0)	// vertical line
	{
		while (y != line.y1 + line.inc_y)
		{
			mlx_put_pixel(img, x, y, 0xFF00FF);
			y += line.inc_y;
		}
	}
	else if (line.dx >= line.dy)	// more horizontal than vertical
	{
		while (x != line.x1 + line.inc_x)
		{
			mlx_put_pixel(img, x, y, 0xFF00FF);
			error += line.slope;
			if (error >= 0)
			{
				y += line.inc_y;
				error += error_inc;
			}
			x += line.inc_x;
		}
	}
	else	// more vertical than horizontal
	{
		while (y != line.y1 + line.inc_y)
		{
			mlx_put_pixel(img, x, y, 0xFF00FF);
			error += line.slope;
			if (error >= 0)
			{
				x += line.inc_x;
				error = error_inc;
			}
			y = line.inc_y;
		}
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	line(img);
	mlx_loop_hook(mlx, &ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
