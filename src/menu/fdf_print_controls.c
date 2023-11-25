/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:04:44 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:07:57 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_print_controls(t_additional	*data)
{
	char	*menu;
	char	*move_right;
	char	*move_left;
	char	*move_up;
	char	*move_down;

	menu = "/// CONTROLS ///";
	move_right = "-> : Move right";
	move_left = "<- : Move left";
	move_down = "|v| : Move down";
	move_up = "|^| : Move up";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 60, 0x03fc35, move_left);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 70, 0x03fc35, move_right);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 80, 0x03fc35, move_down);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 90, 0x03fc35, move_up);
}
