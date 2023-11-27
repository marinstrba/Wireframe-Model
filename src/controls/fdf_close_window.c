/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:27:20 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/27 11:34:02 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

int	close_window(t_additional *data)
{
	free_data(&(data->data));
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
