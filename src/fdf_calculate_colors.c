/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:14 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 18:36:57 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int lerp(int start, int end, float t)
{
    return start + (int)(t * (end - start));
}

int interpolateColors(int color1, int color2, float t)
{
    // Extract individual color components from the colors
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    // Linearly interpolate each component
    int r = lerp(r1, r2, t);
    int g = lerp(g1, g2, t);
    int b = lerp(b1, b2, t);
	
    return (r << 16) | (g << 8) | b;
}

int	get_elevation_color(int z, int min_z, int max_z)
{
	int		low_color;
	int		high_color;
	float	normalized;

	low_color = 0x0000FF;
	high_color = 0xFF0000;
	normalized = (float)(z - min_z) / (max_z - min_z);
	return (interpolateColors(low_color, high_color, normalized));
}
