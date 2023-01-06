/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:23 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/06 13:04:56 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"

/*
- x1 : abscice point de départ
- y1 : ordonnée point de départ
- x2 : abscise point d'arrivé
- y2 : ordonnée point d'arrivé
- x :
- y :
- dx : x2 - x1
- dy : y2 - y1
- m : coefficient directeur
*/
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

# define WIDTH 1200
# define HEIGHT 1000

#endif