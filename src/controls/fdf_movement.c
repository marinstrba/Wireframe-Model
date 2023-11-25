/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:18:17 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:08:31 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

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
