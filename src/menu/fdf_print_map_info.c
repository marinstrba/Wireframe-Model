/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_map_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:05:40 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/27 16:38:29 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_print_map_info(t_additional	*data)
{
	char	*menu;
	char	*min;
	char	*max;
	int		min_z;
	int		max_z;

	find_min_max_z(data->data, &min_z, &max_z);
	menu = ft_strjoin("/// MAP INFO ///", "");
	min = ft_itoa(min_z);
	max = ft_itoa(max_z);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 50, 0x03fc35, menu);
	free(menu);
	menu = ft_strjoin("Lowest point:  ", min);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 60, 0x03fc35, menu);
	free(menu);
	menu = ft_strjoin("Highest point: ", max);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 70, 0x03fc35, menu);
	free(menu);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 80, 0x03fc35, "Zoom: ");
	menu = ft_itoa(data->zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 290, 80, 0x03fc35, menu);
	free(menu);
	free(min);
	free(max);
}
