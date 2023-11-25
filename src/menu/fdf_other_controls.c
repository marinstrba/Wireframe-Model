/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_other_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:11:20 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:29:11 by mstrba           ###   ########.fr       */
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 610, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 610, 60, 0x03fc35, fullscreen);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 610, 70, 0x03fc35, escape);
}
