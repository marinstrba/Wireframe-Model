/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:43 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:09:30 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	calc_param(t_line *line, t_point *data, t_point *ptr, t_additional *ds)
{
	line->z0 = data->z_map;
	line->z1 = ptr->z_map;
	line->x0 = data->x_map * ds->zoom;
	line->y0 = data->y_map * ds->zoom;
	line->x1 = ptr->x_map * ds->zoom;
	line->y1 = ptr->y_map * ds->zoom;
	if (ds->do_isometric)
	{
		isometric(&(line->x0), &(line->y0), line->z0);
		isometric(&(line->x1), &(line->y1), line->z1);
	}
	line->x0 += ds->shift_x;
	line->y0 += ds->shift_y;
	line->x1 += ds->shift_x;
	line->y1 += ds->shift_y;
	find_min_max_z(data, &(line->min_z), &(line->max_z));
	ds->color = get_elevation_color(ds, line->z0, line->min_z, line->max_z);
}
