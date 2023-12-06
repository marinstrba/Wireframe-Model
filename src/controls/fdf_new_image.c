/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:09:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 09:16:03 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_new_image(t_additional	*data)
{
	data->img_pointer = mlx_new_image(data->mlx_ptr, data->screen_width,
			data->screen_height);
	data->img_string = mlx_get_data_addr(data->img_pointer, &(data->bits),
			&(data->lsize), &(data->endian));
}
