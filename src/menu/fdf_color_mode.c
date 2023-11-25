/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:10:27 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:10:49 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_color_mode(t_additional	*data)
{
	char	*menu;

	menu = "///COLOR THEME///";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 460, 50, 0x03fc35, menu);
}
