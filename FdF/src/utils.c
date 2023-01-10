/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:10:54 by tbournon          #+#    #+#             */
/*   Updated: 2023/01/10 16:09:38 by tbournon         ###   ########.fr       */
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

void	line_hook(void *param)
{
	t_line	*line;

	line = (t_line *)param;
}

t_line	initializer(void)
{
	t_line	line;

	line.x0 = 789;
	line.y0 = 900;
	line.x1 = 652;
	line.y1 = 750;
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	line.inc_x = signe(line.dx);
	line.inc_y = signe(line.dy);
	line.slope = 2 * line.dy;
	line.dx = absolute_value(line.dx);
	line.dy = absolute_value(line.dy);
	return (line);
}
