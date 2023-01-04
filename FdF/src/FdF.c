/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/04 12:59:52 by tbournon         ###   ########.fr       */
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
	t_line	line;
	int		width;
	int		height;

	line.x1 = 0;
	line.y1 = 0;
	line.x2 = 14;
	line.y2 = 13;
	line.x = 0;
	line.y = 0;
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.m = line.dy / line.dx;
	width = WIDTH;
	height = 0;
	while (line.x < width)
	{
		line.y = m * line.x + line.y1;
		mlx_put_pixel(img, line.x, line.y, 0xFF000FF);
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
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
