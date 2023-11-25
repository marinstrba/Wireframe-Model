/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:10:27 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:29:51 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_color_mode(t_additional	*data)
{
	char	*menu;
	char	*opt1;
	char	*opt2;
	char	*opt3;
	char	*opt4;

	menu = "///COLOR THEME///";
	opt1 = "No color theme:  1";
	opt2 = "No color theme:  2";
	opt3 = "No color theme:  3";
	opt4 = "No color theme:  4";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 50, 0x03fc35, menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 60, 0x03fc35, opt1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 70, 0x03fc35, opt2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 80, 0x03fc35, opt3);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 90, 0x03fc35, opt4);
}
