/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:57:34 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/27 16:44:32 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_bresenham(t_point *data, t_point	*ptr2, t_additional *dataset)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	calc_par(&line, data, ptr2, dataset);
	draw_line(&line, dataset);
	free(line);
}
