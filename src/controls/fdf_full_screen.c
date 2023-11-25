/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_full_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:17:14 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 13:54:24 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_fs_help(t_additional **dataset)
{
	int			width;
	int			height;
	int			width_prev;
	int			height_prev;

	width_prev = 800;
	height_prev = 600;
	close_window((*dataset));
	mlx_get_screen_size((*dataset)->mlx_ptr, &width, &height);
	if ((*dataset)->full_screen == 0)
	{
		(*dataset)->screen_width = width;
		(*dataset)->screen_height = height;
		(*dataset)->full_screen = 1;
		(*dataset)->shift_x *= width / width_prev;
		(*dataset)->shift_y *= height / height_prev;
	}
	else
	{
		(*dataset)->screen_width = width_prev;
		(*dataset)->screen_height = height_prev;
		(*dataset)->full_screen = 0;
		(*dataset)->shift_x *= width_prev / width;
		(*dataset)->shift_y *= height_prev / height;
	}
}

void	fdf_full_screen(t_additional *dataset)
{
	t_point		*data;
	int			center_x;
	int			center_y;
	int			object_width;
	int			object_height;

	data = dataset->data;
	object_width = dataset->width;
	object_height = dataset->height;
	fdf_fs_help(&dataset);
	center_x = object_width / 2;
	center_y = object_height / 2;
	dataset->shift_x = (dataset->screen_width / 2) - center_x;
	dataset->shift_y = (dataset->screen_height / 2) - center_y;
	fdf_init_screen(&data, dataset);
}
