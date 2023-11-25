/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:59:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 10:56:18 by mstrba           ###   ########.fr       */
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 60, 0x03fc35, move_left);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 70, 0x03fc35, move_right);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 80, 0x03fc35, move_down);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 90, 0x03fc35, move_up);
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 110, 0x03fc35, menu);
	menu = ft_strjoin("Lowest point: ", min);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 120, 0x03fc35, menu);
	menu = ft_strjoin("Highest point: ", max);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 130, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 140, 0x03fc35, "Zoom: ");
	menu = ft_itoa(data->zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 140, 0x03fc35, menu);
}

void	fdf_print_menu(t_additional	*dataset)
{
	fdf_print_map_info(dataset);
	fdf_print_controls(dataset);
}
