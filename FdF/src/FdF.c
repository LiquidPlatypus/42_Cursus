/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/05 14:54:17 by tbournon         ###   ########.fr       */
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
	int		width;
	int		height;

	line.x1 = 0;
	line.y1 = 200;
	line.x2 = 200;
	line.y2 = 80;
	line.e = 0;
	line.x = line.x1;
	line.y = line.y1;
	line.dx = absolute_value(line.x2) - absolute_value(line.x1);
	line.dy = line.y2 - line.y1;
	line.m = line.dy / line.dx;
	width = WIDTH;
	height = 0;
	while (line.x < line.x2)
	{
		//line.y = line.m * line.x + line.y1 + 0.5;
		mlx_put_pixel(img, line.x, line.y, 0xFF000FF);
		line.e -= line.m;
		if (line.e < -0.5)
		{
			line.y--;
			line.e += 1.0;
		}
		line.x++;
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
