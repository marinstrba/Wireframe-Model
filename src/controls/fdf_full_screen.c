/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_full_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:17:14 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:15:49 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_fs_help(t_additional **dataset)
{
	int			width;
	int			height;
	int			width_prev;
	int			height_prev;

	width_prev = 800;
	height_prev = 600;
	mlx_destroy_window((*dataset)->mlx_ptr, (*dataset)->win_ptr);
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

	data = dataset->data;
	fdf_fs_help(&dataset);
	fdf_init_screen(&data, dataset);
}
