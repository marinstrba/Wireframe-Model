/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/24 16:22:22 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"


// void	calc_param(t_line *line, t_point *data, t_point *ptr2, t_additional *dataset)
// {
// 	line->z0 = data->z_map;
// 	line->z1 = ptr2->z_map;
// 	line->x0 = data->x_map * dataset->zoom;
// 	line->y0 = data->y_map * dataset->zoom;
// 	line->x1 = ptr2->x_map * dataset->zoom;
// 	line->y1 = ptr2->y_map * dataset->zoom;
// 	isometric(&(line->x0), &(line->y0), line->z0);
// 	isometric(&(line->x1), &(line->y1), line->z1);
// 	line->x0 += 450;
// 	line->y0 += 450;
// 	line->x1 += 450;
// 	line->y1 += 450;
// }

// void draw_line(t_line *line, t_additional *dataset)
// {
// 	int err, e2;
// 	int dx = abs(line->x1 - line->x0);
// 	int dy = -abs(line->y1 - line->y0);
// 	int sx = line->x0 < line->x1 ? 1 : -1;
// 	int sy = line->y0 < line->y1 ? 1 : -1;

// 	err = dx + dy;

// 	while (1)
// 	{
// 		mlx_pixel_put(dataset->mlx_ptr, dataset->win_ptr, line->x0, line->y0, dataset->color);
// 		if (line->x0 == line->x1 && line->y0 == line->y1)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			line->x0 += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			line->y0 += sy;
// 		}
// 	}
// }

// void	fdf_bresenham(t_point *data, t_point	*ptr2, t_additional *dataset)
// {
// 	t_line	line;

// 	calc_param(&line, data, ptr2, dataset);
// 	draw_line(&line, dataset);
// }

void	fdf_bresenham_algorithm(t_point *data, t_additional *dataset, int x1, int y1, t_point* ptr2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x0;
	int	y0;
	int	z;
	int z1;
	int	minz;
	int	maxz;
	minz = 0;
	maxz = 0;

	z = data->z_map;
	z1 = ptr2->z_map;
	
	// ZOOM
	x0 = data->x_map * dataset->zoom;
	y0 = data->y_map * dataset->zoom;
	x1 *= dataset->zoom;
	y1 *= dataset->zoom;
	// COLOR
	
	find_min_max_z(data, &minz, &maxz);
	//dataset->color = get_elevation_color(z, minz, maxz);

	// 3D
	isometric(&x0, &y0, z);
	isometric(&x1, &y1, z1);

	//SHIFT
	x0 += dataset->shift_x;
	y0 += dataset->shift_y;
	x1 += dataset->shift_x;
	y1 += dataset->shift_y;
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;

	while (1)
	{
		mlx_pixel_put(dataset->mlx_ptr, dataset->win_ptr, x0, y0, dataset->color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}



void	fdf_draw_down(t_point	*ptr1, t_point	*ptr2, t_additional	*data)
{
	t_point	*draw_down_ptr;
	int		index;
	int		x;
	int		y;

	draw_down_ptr = ptr1;
	index = 0;
	while (index < data->width)
	{
		draw_down_ptr = draw_down_ptr->next;
		index++;
	}
	index = 0;
	while (index < data->width)
	{
		x = draw_down_ptr->x_map;
		y = draw_down_ptr->y_map;
		// fdf_bresenham_algorithm(ptr1, draw_down_ptr, data);
		fdf_bresenham_algorithm(ptr1, data, x, y, ptr2);
		draw_down_ptr = draw_down_ptr->next;
		ptr1 = ptr1->next;
		index++;
	}
	ptr2 = ptr2;
}

void	fdf_draw(t_point	*data, t_additional	*dataset)
{
	t_point	*ptr1;
	t_point	*ptr2;
	t_point	*ptr3;
	int		index;

	ptr1 = data;
	ptr2 = data;
	index = 0;
	fdf_print_menu(dataset);
	while (ptr1->next != NULL)
	{
		ptr3 = ptr1;
		while (ptr2->next != NULL && ptr2->next->y_map == ptr1->y_map)
		{
			ptr2 = ptr2->next;
			// fdf_bresenham_algorithm(ptr1, ptr2, dataset);
			fdf_bresenham_algorithm(ptr1, dataset, ptr2->x_map, ptr2->y_map, ptr2);
			ptr1 = ptr2;
		}
		ptr1 = ptr3;
		if (index++ == (dataset->height - 1))
			break ;
		fdf_draw_down(ptr1, ptr2, dataset);
		ptr2 = ptr2->next;
		ptr1 = ptr2;
	}
}
