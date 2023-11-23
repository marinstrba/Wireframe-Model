/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 09:19:26 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	isometric(int	*x, int	*y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * cos(0.8) - z;
}

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

	z = data->z_map;// * dataset->zoom;
	z1 = ptr2->z_map;
	// ZOOM
	x0 = data->x_map * dataset->zoom;
	y0 = data->y_map * dataset->zoom;
	x1 *= dataset->zoom;
	y1 *= dataset->zoom;
	// COLOR
	dataset->color = (z > 0) ? 0xe80c0c : 0xffffff;
	
	// // 3D
	isometric(&x0, &y0, z);
	isometric(&x1, &y1, z1);

	//SHIFT
	x0 += 450;
	y0 += 450;
	x1 += 450;
	y1 += 450;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;  /* error value e_xy */

	while (1) {
		mlx_pixel_put(dataset->mlx_ptr, dataset->win_ptr, x0, y0, dataset->color);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { /* e_xy+e_x > 0 */
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) { /* e_xy+e_y < 0 */
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
		//printf("I am in the function that iterates to get draw down point by width tines >>> X: %d Y: %d\n\n\n", draw_down_ptr->x_map, draw_down_ptr->y_map);
		draw_down_ptr = draw_down_ptr->next;
		index++;
	}
	index = 0;
	//printf("I am NOT in the function that iterates to get draw down point by width tines >>> X: %d Y: %d\n\n\n", draw_down_ptr->x_map, draw_down_ptr->y_map);
	while (index < data->width)
	{
		x = draw_down_ptr->x_map;
		y = draw_down_ptr->y_map;
		// printf("This is X cordinate of ptr1 >> %d\n", ptr1->x_map);
		// printf("This is Y cordinate of ptr1 >> %d\n", ptr1->y_map);
		// printf("This is X cordinate of draw_down_ptr >> %d\n", x);
		// printf("This is Y cordinate of draw_down_ptr >> %d\n", y);
		fdf_bresenham_algorithm(ptr1, data, x, y, ptr2);
		//printf("PASSED through bresenham algorithm\n");
		draw_down_ptr = draw_down_ptr->next;
		ptr1 = ptr1->next;
		// printf("This is index of draw down >> %d\n\n", index);
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
	while (ptr1->next != NULL)
	{
		ptr3 = ptr1;
		while (ptr2->next != NULL && ptr2->next->y_map == ptr1->y_map)
		{
			ptr2 = ptr2->next;
			fdf_bresenham_algorithm(ptr1, dataset, ptr2->x_map, ptr2->y_map, ptr2);
			ptr1 = ptr2;
		}
		ptr1 = ptr3;
		// printf("This is X cordinate of ptr1 >> %d\n", ptr1->x_map);
		// printf("This is Y cordinate of ptr1 >> %d\n\n", ptr1->y_map);
		// printf("This is X cordinate of ptr2 >> %d\n", ptr2->x_map);
		// printf("This is Y cordinate of ptr2 >> %d\n\n", ptr2->y_map);
		// printf("PASSED through bresenham algorithm\n");
		if (index == (dataset->height - 1))
			break ;
		fdf_draw_down(ptr1, ptr2, dataset);
		//printf("PASSES through draw down function\n");
		ptr2 = ptr2->next;
		ptr1 = ptr2;
		index++;
		//printf("This is index >> %d\n", index);
	}
}
