/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:59:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 11:34:17 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

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

void	fdf_print_map_info(t_additional	*data)
{
	char	*menu;
	char	*min;
	char	*max;
	int		min_z;
	int		max_z;

	find_min_max_z(data->data, &min_z, &max_z);
	menu = "/// MAP INFO ///";
	min = ft_itoa(min_z);
	max = ft_itoa(max_z);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 50, 0x03fc35, menu);
	menu = ft_strjoin("Lowest point:  ", min);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 60, 0x03fc35, menu);
	menu = ft_strjoin("Highest point: ", max);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 70, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 80, 0x03fc35, "Zoom: ");
	menu = ft_itoa(data->zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 290, 80, 0x03fc35, menu);
}

void	fdf_isometric_mode(t_additional	*data)
{
	char	*menu;
	char	*on;
	char	*off;


	menu = "///ISOMETRIC MODE///";
	on = "ON : y";
	off = "OFF : n";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 325, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 325, 60, 0x03fc35, on);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 325, 70, 0x03fc35, off);
}

void	fdf_color_mode(t_additional	*data)
{
	char	*menu;

	menu = "///COLOR THEME///";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 50, 0x03fc35, menu);
}

void	fdf_other_controls(t_additional	*data)
{
	char	*menu;
	char	*fullscreen;
	char	*escape;

	menu = "///OTHERS///";
	fullscreen = "Fullscreen mode: f";
	escape = "Close window:  esc";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 590, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 590, 60, 0x03fc35, fullscreen);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 590, 70, 0x03fc35, escape);
}

void	fdf_print_menu(t_additional	*dataset)
{
	fdf_print_map_info(dataset);
	fdf_print_controls(dataset);
	fdf_isometric_mode(dataset);
	fdf_color_mode(dataset);
	fdf_other_controls(dataset);
}
