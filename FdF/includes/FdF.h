/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:00:23 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/04 15:56:00 by tbournon         ###   ########.fr       */
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
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x;
	float	y;
	float	dx; // TODO : mettre en valeur absolue et non en float
	float	dy; // TODO : mettre en valeur absolue et non en float
	float	m; // TODO : mettre en valeur absolue et non en float
}		t_line;

# define WIDTH 1200
# define HEIGHT 1000

#endif