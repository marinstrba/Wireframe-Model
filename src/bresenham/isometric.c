/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:27 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 11:19:55 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	isometric(int	*x, int	*y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * cos(0.8) - z;
}

void	fdf_do_isometric(int keycode, t_additional *dataset)
{
	if (keycode == YES)
		dataset->do_isometric = 1;
	else if (keycode == NO)
		dataset->do_isometric = 0;
}
