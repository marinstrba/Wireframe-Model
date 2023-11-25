/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:09:26 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:08:04 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

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
