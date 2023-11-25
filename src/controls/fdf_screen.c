/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:29:05 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:08:22 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_init_screen(t_point **cordinates, t_additional *data)
{
	int	scw;
	int	sch;

	scw = data->screen_width;
	sch = data->screen_height;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, scw, sch, "Wireframe");
	fdf_draw(*cordinates, data);
	mlx_key_hook(data->win_ptr, fdf_controls_key_press, data);
	mlx_mouse_hook(data->win_ptr, fdf_controls_mouse, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
