/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_z_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:23:55 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 18:37:10 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	find_min_max_z(t_point *head, int *minZ, int *maxZ)
{
	t_point	*current;

	*minZ = INT_MAX;
	*maxZ = INT_MIN;
	current = head;
	while (current != NULL)
	{
		if (current->z_map > *maxZ)
			*maxZ = current->z_map;
		if (current->z_map < *minZ)
			*minZ = current->z_map;
		current = current->next;
	}
}
