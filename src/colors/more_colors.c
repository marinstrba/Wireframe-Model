/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:15:41 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:09:07 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

int	lerp(int start, int end, float t)
{
	return (start + (int)(t * (end - start)));
}

int	get_red_component(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green_component(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue_component(int color)
{
	return (color & 0xFF);
}

int	combine_colors(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
