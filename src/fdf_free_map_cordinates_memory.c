/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_map_cordinates_memory.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:47:05 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/20 13:48:50 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/LIBFT/libft.h"

void	free_map_coordinates(t_point **map_coordinates)
{
	t_point	*current;
	t_point	*next;

	current = *map_coordinates;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*map_coordinates = NULL;
}
