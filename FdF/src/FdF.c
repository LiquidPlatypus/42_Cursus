/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/04 09:41:40 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <stdlib.h> // !                                                
#include <stdio.h> // !                                                 
#include <unistd.h> // !                                                

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	// TODO : A REMPLACER AVEC MON PROPRE PRINTF
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void	line(mlx_image_t *img)
{
	int		y1;
	int		x;
	float	y;
	int		width;
	int		height;

	y1 = 0;
	x = 0;
	y = 0;
	width = WIDTH;
	height = 0;
	while (x < width)
	{
		y = 0.7 * x + y1;
		mlx_put_pixel(img, x, y, 0xFF000FF);
		x++;
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
	//mlx_put_pixel(img, 128, 128, 0xFF000FF);
	line(img);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
