/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_deal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:00 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:19:17 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	fdf_controls_key_press(int keycode, t_additional *dataset)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(dataset->mlx_ptr, dataset->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_F)
		fdf_full_screen(dataset);
	else if (keycode == YES || keycode == NO)
		fdf_do_isometric(keycode, dataset);
	else
		fdf_movement_keys(keycode, dataset);
	return (0);
}
