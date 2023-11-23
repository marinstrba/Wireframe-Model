/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:29:05 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 17:59:22 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_init_screen(t_point	**cordinates, t_additional	*dataset)
{
	dataset->mlx_ptr = mlx_init();
	dataset->win_ptr = mlx_new_window(dataset->mlx_ptr, dataset->screen_width, dataset->screen_height, "FDF");
	fdf_draw(*cordinates, dataset);
	mlx_key_hook(dataset->win_ptr, fdf_controls_key_press, dataset);
	mlx_mouse_hook(dataset->win_ptr, fdf_controls_mouse_scroll, dataset);
	mlx_hook(dataset->win_ptr, 17, 0, close_window, dataset);
	mlx_loop(dataset->mlx_ptr);
}
