/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/05 10:14:10 by tbournon         ###   ########.fr       */
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
	const mlx_t	*mlx;

	mlx = param;
	// TODO : A REMPLACER AVEC MON PROPRE PRINTF
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void	line(mlx_image_t *img)
{
	t_line	line;
	int		width;
	int		height;

	line.x1 = 0;
	line.y1 = 0;
	line.x2 = 1199;
	line.y2 = 899;
	line.x = 0;
	line.y = 0;
	line.dx = absolute_value(line.x2) - absolute_value(line.x1);
	line.dy = line.y2 - line.y1;
	line.m = line.dy / line.dx;
	width = WIDTH;
	height = 0;
	while (line.x < width)
	{
		line.y = line.m * line.x + line.y1 + 0.5;
		mlx_put_pixel(img, line.x, line.y, 0xFF000FF);
		line.x++;
	}
}

void	input_hook(mlx_key_data_t keydata, mlx_t *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
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
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(mlx, &input_hook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
