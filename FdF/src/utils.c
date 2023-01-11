/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:10:54 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/11 11:11:28 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

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

t_line	initializer(mlx_t *mlx)
{
	t_line	line;

	if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_LEFT))
		mlx_get_mouse_pos(mlx, &line.x0, &line.y0);
	if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_RIGHT))
		mlx_get_mouse_pos(mlx, &line.x1, &line.y1);
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	line.inc_x = signe(line.dx);
	line.inc_y = signe(line.dy);
	line.slope = 2 * line.dy;
	line.dx = absolute_value(line.dx);
	line.dy = absolute_value(line.dy);
	return (line);
}
