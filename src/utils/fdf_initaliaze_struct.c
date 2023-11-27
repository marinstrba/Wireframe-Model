/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initaliaze_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:00:33 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/27 16:37:50 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_initialize_struct(t_additional	**data)
{
	(*data)->zoom = 2;
	(*data)->screen_height = 600;
	(*data)->screen_width = 800;
	(*data)->full_screen = 0;
	(*data)->shift_x = 370;
	(*data)->shift_y = 150;
	(*data)->color = 0xffffff;
	(*data)->do_isometric = 1;
	(*data)->color_low = 0xffffff;
	(*data)->color_high = 0xffffff;
}
