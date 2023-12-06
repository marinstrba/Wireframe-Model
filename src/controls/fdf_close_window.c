/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:27:20 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 11:22:21 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

int	close_window(t_additional *data)
{
	free_data(&(data->data));
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->img_string);
	free(data->img_pointer);
	free(data->line);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}
