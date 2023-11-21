/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/21 21:44:23 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_bresenham_algorithm(t_point	*data, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;
	int	x0;

	x0 = data->x_map;
	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * (dy - dx);
	while (x0 <= x1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xffffff);
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

void	fdf_draw(t_point	*data)
{
	t_point	*current;
	int		y0;
	int		x1;
	int		y1;

	current = data;
	y0 = current->y_map;
	while (current->next != NULL)
		current = current->next;
	x1 = current->x_map;
	y1 = current->y_map;
	fdf_bresenham_algorithm(data, y0, x1, y1);
}
