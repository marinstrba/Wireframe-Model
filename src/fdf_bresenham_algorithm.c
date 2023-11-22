/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/22 12:56:01 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_bresenham_algorithm(t_point	*data, t_additional	*dataset, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;
	int	x0;
	int	y0;

	x0 = data->x_map;
	y0 = data->y_map;
	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * (dy - dx);
	while (x0 <= x1)
	{
		mlx_pixel_put(dataset->mlx_ptr, dataset->win_ptr, x0, y0, 0xffffff);
		if (p < 0)
			p += 2 * dy;
		else
		{
			y0++;
			p += 2 * (dy - dx);
		}
		x0++;
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
	while (index < data->height)
	{
		draw_down_ptr = draw_down_ptr->next;
		index++;
	}
	index = 0;
	while (index < data->height)
	{
		x = draw_down_ptr->x_map;
		y = draw_down_ptr->y_map;
		printf("This is X cordinate of ptr1 >> %d\n", ptr1->x_map);
		printf("This is Y cordinate of ptr1 >> %d\n", ptr1->y_map);
		printf("This is X cordinate of draw_down_ptr >> %d\n", x);
		printf("This is Y cordinate of draw_down_ptr >> %d\n", y);
		fdf_bresenham_algorithm(ptr1, data, x, y);
		//printf("PASSED through bresenham algorithm\n");
		draw_down_ptr = draw_down_ptr->next;
		ptr1 = ptr1->next;
		printf("This is index of draw down >> %d\n\n", index);
		index++;
	}
	ptr1 = ptr2;
}

void	fdf_draw(t_point	*data, t_additional	*dataset)
{
	t_point	*ptr1;
	t_point	*ptr2;
	int		index;

	ptr1 = data;
	ptr2 = data;
	index = 0;
	while (ptr1->next != NULL)
	{
		while (ptr2->next != NULL && ptr2->next->y_map == ptr1->y_map)
			ptr2 = ptr2->next;
		printf("This is X cordinate of ptr1 >> %d\n", ptr1->x_map);
		printf("This is Y cordinate of ptr1 >> %d\n\n", ptr1->y_map);
		printf("This is X cordinate of ptr2 >> %d\n", ptr2->x_map);
		printf("This is Y cordinate of ptr2 >> %d\n\n", ptr2->y_map);
		fdf_bresenham_algorithm(data, dataset, ptr2->x_map, ptr2->y_map);
		printf("PASSED through bresenham algorithm\n");
		if (index == (dataset->height - 1))
			break ;
		fdf_draw_down(ptr1, ptr2, dataset);
		printf("PASSES through draw down function\n");
		ptr2 = ptr2->next;
		ptr1 = ptr2;
		index++;
		printf("This is index >> %d\n", index);
		if (index == (dataset->height - 1))
			break ;
	}
}
