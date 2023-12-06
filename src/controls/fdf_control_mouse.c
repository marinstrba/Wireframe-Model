/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:18:51 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 11:23:55 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

int	fdf_controls_mouse(int mousecode, int x, int y, t_additional *dataset)
{
	t_point	*data;

	(void)x;
	(void)y;
	data = dataset->data;
	if (mousecode == 4)
		dataset->zoom += 1;
	else if (mousecode == 5)
		dataset->zoom -= 1;
	if (dataset->zoom < 1)
		dataset->zoom = 1;
	fdf_init_screen(&(data), dataset);
	return (0);
}
