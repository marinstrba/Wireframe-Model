/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_other_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:11:20 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:11:33 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

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
