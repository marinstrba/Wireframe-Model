/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:33:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:08:50 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_color_mode_control(int keycode, t_additional *dataset)
{
	if (keycode == ONE)
	{
		dataset->color_low = 0xffffff;
		dataset->color_high = 0xffffff;
	}
	else if (keycode == TWO)
	{
		dataset->color_low = 0x08D9D6;
		dataset->color_high = 0xFF2E63;
	}
	else if (keycode == THREE)
	{
		dataset->color_low = 0x39A7FF;
		dataset->color_high = 0x557C55;
	}
	else if (keycode == FOUR)
	{
		dataset->color_low = 0x994D1C;
		dataset->color_high = 0x7B66FF;
	}
	mlx_clear_window(dataset->mlx_ptr, dataset->win_ptr);
	fdf_draw(dataset->data, dataset);
}
