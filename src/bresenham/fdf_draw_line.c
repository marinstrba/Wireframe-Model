/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:21:19 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 09:13:36 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	draw_line(t_line **line, t_additional *dt)
{
	int	e2;
	int	col;

	init_line_vars(&(line));
	col = dt->color;
	while (1)
	{
		my_pixel_put(dt, (*line)->x0, (*line)->y0, col);
		//mlx_pixel_put(dt->mlx_ptr, dt->win_ptr, (*line)->x0, (*line)->y0, col);
		if ((*line)->x0 == (*line)->x1 && (*line)->y0 == (*line)->y1)
			break ;
		e2 = 2 * (*line)->err;
		if (e2 >= (*line)->dy)
		{
			(*line)->err += (*line)->dy;
			(*line)->x0 += (*line)->sx;
		}
		if (e2 <= (*line)->dx)
		{
			(*line)->err += (*line)->dx;
			(*line)->y0 += (*line)->sy;
		}
	}
}
