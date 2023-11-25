/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:14 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:53:26 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

float	normalize(int z, int min_z, int max_z)
{
	return ((float)(z - min_z) / (max_z - min_z));
}

int	ic(int c1, int c2, float t)
{
	return (lerp(c1, c2, t));
}

int	get_elevation_color(t_additional	*ds, int z, int min_z, int max_z)
{
	int		low;
	int		high;
	float	norm;

	low = ds->color_low;
	high = ds->color_high;
	norm = normalize(z, min_z, max_z);
	return (combine_colors(
			ic(get_red_component(low), get_red_component(high), norm),
			ic(get_green_component(low), get_green_component(high), norm),
			ic(get_blue_component(low), get_blue_component(high), norm)
		));
}
