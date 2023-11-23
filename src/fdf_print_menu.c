/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:59:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 11:20:10 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_print_controls(t_additional	*dataset)
{
	char	*menu;

	menu = "/// CONTROLS ///";
	mlx_string_put(dataset->mlx_ptr, dataset->win_ptr, 50, 50, 0x03fc35, menu);
}

void	fdf_print_map_info(t_additional	*dataset)
{
	char	*menu;

	menu = "/// MAP INFO ///";
	mlx_string_put(dataset->mlx_ptr, dataset->win_ptr, 50, 100, 0x03fc35, menu);
}

void	fdf_print_menu(t_additional	*dataset)
{
	fdf_print_map_info(dataset);
	fdf_print_controls(dataset);
}
