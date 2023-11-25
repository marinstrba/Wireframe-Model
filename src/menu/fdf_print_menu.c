/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:59:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:07:49 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_print_menu(t_additional	*dataset)
{
	fdf_print_map_info(dataset);
	fdf_print_controls(dataset);
	fdf_isometric_mode(dataset);
	fdf_color_mode(dataset);
	fdf_other_controls(dataset);
}
