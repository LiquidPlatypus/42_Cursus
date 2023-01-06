/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/06 11:22:26 by tbournon         ###   ########.fr       */
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
	float	y;
	float	error;
	float	error_inc;

	line.x0 = 0;
	line.y0 = 0;
	line.x1 = 300;
	line.y1 = 100;
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	line.slope = 2 * line.dy;
	x = 0;
	y = line.y0;
	error = -line.dx;
	error_inc = -2 * line.dx;
	while (x <= line.x1)
	{
		mlx_put_pixel(img, x, y, 0xFF000FF);
		error += line.slope;
		if (error >= 0.0)
		{
			y++;
			error += error_inc;
		}
		++x;
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
