/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_deal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:00 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 18:09:01 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	fdf_controls_mouse_scroll(int mousecode, int x, int y, t_additional *dataset)
{
	t_point	*data;
	 (void)x;  // Explicitly mark x as unused
    (void)y;

	data = dataset->data;
    if (mousecode == 4) // Scroll up
        dataset->zoom += 1;
    else if (mousecode == 5) // Scroll down
        dataset->zoom -= 1;

    if (dataset->zoom < 1) // Prevent zooming out too much
        dataset->zoom = 1;

    mlx_clear_window(dataset->mlx_ptr, dataset->win_ptr);
    fdf_draw(data, dataset); // Redraw with new zoom level
    return (0);
}


void	fdf_movement_keys(int keycode, t_additional *dataset)
{
	t_point	*data;

	data = dataset->data;
	if (keycode == KEY_LEFT)
		dataset->shift_x -= 10;
	else if (keycode == KEY_UP)
		dataset->shift_y -= 10;
	else if (keycode == KEY_RIGHT)
		dataset->shift_x += 10;
	else if (keycode == KEY_DOWN)
		dataset->shift_y += 10;
	mlx_clear_window(dataset->mlx_ptr, dataset->win_ptr);
	fdf_draw(data, dataset);
}

void	fdf_full_screen(t_additional *dataset)
{
	t_point		*data;
	int			width;
	int			height;
	int			width_prev;
	int			height_prev;

	data = dataset->data;
	width_prev = 800;
	height_prev = 600;
	close_window(dataset);
	mlx_get_screen_size(dataset->mlx_ptr, &width, &height);
	if (dataset->full_screen == 0)
	{
		dataset->screen_width = width;
		dataset->screen_height = height;
		dataset->full_screen = 1;
		dataset->shift_x *= width / width_prev;
		dataset->shift_y *= height / height_prev;
	}
	else
	{
		dataset->screen_width = width_prev;
		dataset->screen_height = height_prev;
		dataset->full_screen = 0;
		dataset->shift_x *= width_prev / width;
		dataset->shift_y *= height_prev / height;
	}
	fdf_init_screen(&data, dataset);
}



int	fdf_controls_key_press(int keycode, t_additional *dataset)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(dataset->mlx_ptr, dataset->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_F)
		fdf_full_screen(dataset);
	else
		fdf_movement_keys(keycode, dataset);
	return (0);
}

int	close_window(t_additional *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

