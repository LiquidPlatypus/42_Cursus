/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:15 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/27 10:56:24 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <stdlib.h> // !                                                
#include <stdio.h> // !                                                 
#include <unistd.h> // !                                                
#include <string.h> // !                                                
#define BPP sizeof(int32_t) // !                                        

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno)); // TODO : REMPLACER PAR MON PROPRE fprintf
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height); // TODO : REMPLACER PAR MON PROPRE printf
}

int	main(void)
{
	// MLX allow you tod efine its core behavior before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t	*mlx = mlx_init(WIDTH, HEIGTH, "42", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t	*img = mlx_new_image(mlx, 128, 128);
	
	// Set the channels of each pixel in our image to the maximum byte value of 255
	memset(img->pixels, 255, img->width * img->height * BPP);

	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Register a hook and âss mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
