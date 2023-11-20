/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:50:23 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/20 12:31:35 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/LIBFT/libft.h"

int	convert_to_cordinates(int	***cordinates, char	*line, int y_cordinate)
{
	char			**seperated_characters;
	int				elements_added;
	int				index;
	int				num;

	index = y_cordinate;
	elements_added = 0;
	seperated_characters = ft_split(line, ' ');
	while (seperated_characters && seperated_characters[elements_added])
	{
		(*cordinates)[index] = (int *) malloc (sizeof(int) * 3);
		if (!(*cordinates)[index] || !seperated_characters)
		{
			fdf_failed_malloc();
		}
		num = ft_atoi(seperated_characters[elements_added]);
		(*cordinates)[index][2] = num;
		(*cordinates)[index][1] = y_cordinate;
		(*cordinates)[index][0] = elements_added;
		free(seperated_characters[elements_added]);
		index++;
		elements_added++;
	}
	free (seperated_characters);
	return (elements_added);
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
	index = -1;
	while (++index < *bytes_allocated)
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
	int		elements_to_add;
	int		**cordinates;

	bytes_usage = 0;
	elements_to_add = 0;
	bytes_allocated = 10;
	cordinates = (int **)malloc(sizeof(int *) * bytes_allocated);
	if (!cordinates)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		elements_to_add = convert_to_cordinates(&cordinates, line, bytes_usage);
		free(line);
		while (bytes_usage + elements_to_add > bytes_allocated)
			fdf_reallocate_cordinates(&cordinates, &bytes_allocated);
		bytes_usage += elements_to_add;
	}
	return (cordinates);
}
