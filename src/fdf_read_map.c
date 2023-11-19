/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:50:23 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 20:33:09 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/LIBFT/libft.h"

void	convert_to_cordinates(int	***cordinates, char	*line, int y_cordinate)
{
	char	**seperated_characters;
	int		index;
	int		num;

	index = 0;
	seperated_characters = ft_split(line, ' ');
	while (seperated_characters && seperated_characters[index])
	{
		(*cordinates)[index] = (int *) malloc (sizeof(int) * 3);
		if (!(*cordinates)[index])
		{
			fdf_failed_malloc();
			exit(EXIT_FAILURE);
		}
		num = ft_atoi(seperated_characters[index]);
		(*cordinates)[index][2] = num;
		(*cordinates)[index][1] = y_cordinate;
		(*cordinates)[index][0] = index;
		free(seperated_characters[index]);
		index++;
	}
	free (seperated_characters);
}

void	fdf_reallocate_cordinates(int	***cordinates, int *bytes_allocated)
{
	int	index;
	int	new_size;
	int	**new_cordinates;

	index = 0;
	new_size = *bytes_allocated * 2;
	new_cordinates = (int **) malloc (sizeof(int *) * new_size);
	if (!new_cordinates)
	{
		while (index < *bytes_allocated)
		{
			free((*cordinates)[index]);
			index++;
		}
		free(*cordinates);
		fdf_failed_malloc();
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < *bytes_allocated)
		new_cordinates[index] = (*cordinates)[index];
	free(*cordinates);
	*cordinates = new_cordinates;
	*bytes_allocated = new_size;
}

int	**fdf_read_map(int fd)
{
	char	*line;
	int		bytes_allocated;
	int		bytes_usage;
	int		**cordinates;

	bytes_usage = 0;
	bytes_allocated = 1;
	cordinates = (int **)malloc(sizeof(int *) * bytes_allocated);
	if (!cordinates)
		return (NULL);
	while (1)
	{
		if (bytes_usage + 1 == bytes_allocated)
			fdf_reallocate_cordinates(&cordinates, &bytes_allocated);
		line = get_next_line(fd);
		if (!line)
			break ;
		convert_to_cordinates(&cordinates, line, bytes_usage);
		bytes_usage++;
	}
	return (cordinates);
}
