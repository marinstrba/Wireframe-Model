/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:50:23 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 19:29:13 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/LIBFT/libft.h"

int	*convert_to_coordinates(int	***coordinates, char	*line)
{
	char	**seperated_characters;
	char	*numbers;
	int		index;

	index = 0;
	seperated_characters = ft_split(line, " ");
	while (seperated_characters)
	{
		
	}
}

void	fdf_reallocate_coordinates_memory(int	**coordinates, int *bytes)
{

}

int	**fdf_read_map(int fd)
{
	char	*line;
	int		bytes_allocated;
	int		bytes_usage;
	int		**coordinates;

	bytes_usage = 0;
	bytes_allocated = 1;
	coordinates = (int **)malloc(sizeof(int *) * bytes_allocated);
	if (!coordinates)
		return (NULL);
	while (1)
	{
		if (bytes_usage + 1 == bytes_allocated)
			fdf_reallocate_coordinates_memory(&coordinates, &bytes_allocated);
		line = get_next_line(fd);
		if (!line)
			break ;
		convert_to_coordinates(&coordinates, line);
		bytes_usage++;
	}
	return (coordinates);
}
