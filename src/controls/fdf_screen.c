/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:29:05 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 11:28:48 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_init_screen(t_point **cordinates, t_additional *data)
{
	free(data->img_string);
	free(data->img_pointer);
	fdf_new_image(data);
	fdf_draw(*cordinates, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_pointer, 0, 0);
	fdf_print_menu(data);
	mlx_key_hook(data->win_ptr, fdf_controls_key_press, data);
	mlx_mouse_hook(data->win_ptr, fdf_controls_mouse, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
