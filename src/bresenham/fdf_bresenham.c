/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:57:34 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 11:20:59 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	calc_param(t_line *line, t_point *data, t_point *ptr2, t_additional *ds)
{
	line->z0 = data->z_map;
	line->z1 = ptr2->z_map;
	line->x0 = data->x_map * ds->zoom;
	line->y0 = data->y_map * ds->zoom;
	line->x1 = ptr2->x_map * ds->zoom;
	line->y1 = ptr2->y_map * ds->zoom;
	if (ds->do_isometric)
	{
		isometric(&(line->x0), &(line->y0), line->z0);
		isometric(&(line->x1), &(line->y1), line->z1);
	}
	line->x0 += 450;
	line->y0 += 450;
	line->x1 += 450;
	line->y1 += 450;
	find_min_max_z(data, &(line->min_z), &(line->max_z));
	ds->color = get_elevation_color(line->z0, line->min_z, line->max_z);
}

void	init_line_vars(t_line *line)
{
	line->dx = abs(line->x1 - line->x0);
	line->dy = -abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
}

void	draw_line(t_line *line, t_additional *dt)
{
	int	e2;

	init_line_vars(line);
	while (1)
	{
		mlx_pixel_put(dt->mlx_ptr, dt->win_ptr, line->x0, line->y0, dt->color);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		e2 = 2 * line->err;
		if (e2 >= line->dy)
		{
			line->err += line->dy;
			line->x0 += line->sx;
		}
		if (e2 <= line->dx)
		{
			line->err += line->dx;
			line->y0 += line->sy;
		}
	}
}

void	fdf_bresenham(t_point *data, t_point	*ptr2, t_additional *dataset)
{
	t_line	line;

	calc_param(&line, data, ptr2, dataset);
	draw_line(&line, dataset);
}
