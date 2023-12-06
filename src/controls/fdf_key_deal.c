/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_deal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:00 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 10:41:35 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

int	fdf_controls_key_press(int keycode, t_additional *dataset)
{
	if (keycode == KEY_ESC)
	{
		close_window(dataset);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_F)
		fdf_full_screen(dataset);
	else if (keycode == YES || keycode == NO)
		fdf_do_isometric(keycode, dataset);
	else if (keycode == ONE || keycode == TWO)
		fdf_color_mode_control(keycode, dataset);
	else if (keycode == THREE || keycode == FOUR)
		fdf_color_mode_control(keycode, dataset);
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		fdf_movement_keys(keycode, dataset);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		fdf_movement_keys(keycode, dataset);
	return (0);
}
