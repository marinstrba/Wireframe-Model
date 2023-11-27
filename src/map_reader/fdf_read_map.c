/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:50:23 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/27 16:39:14 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_add_node(t_point	**new_node)
{
	*new_node = malloc(sizeof(t_point));
	if (!(*new_node))
	{
		fdf_failed_malloc();
		exit(0);
	}
}

void	fdf_add_node_last(t_point	*head, t_point	*node)
{
	t_point	*new_head;

	new_head = head;
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = node;
}

void	convert_cordinates(char	*line, t_point	**head, int y)
{
	char	**seperated_characters;
	t_point	*new_node;
	int		index;

	index = 0;
	seperated_characters = ft_split(line, ' ');
	while (seperated_characters && seperated_characters[index])
	{
		fdf_add_node(&new_node);
		new_node->x_map = index;
		new_node->y_map = y;
		new_node->z_map = ft_atoi(seperated_characters[index]);
		new_node->next = NULL;
		if (!*head)
			*head = new_node;
		else
			fdf_add_node_last(*head, new_node);
		index++;
	}
	free_2d_array(seperated_characters);
}

void	count_chars(t_additional	***dataset, char	*line)
{
	int		num_chars;
	char	**chars;

	num_chars = 0;
	chars = ft_split(line, ' ');
	while (chars[num_chars])
		num_chars++;
	(**dataset)->width = num_chars;
	free_2d_array(chars);
}

t_point	*fdf_read_map(int fd, t_additional	**dataset)
{
	t_point	*head;
	char	*line;
	int		y_cordinate;

	head = NULL;
	y_cordinate = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (((*dataset)->width) == 0)
			count_chars(&dataset, line);
		convert_cordinates(line, &head, y_cordinate);
		free(line);
		y_cordinate++;
	}
	(*dataset)->height = y_cordinate;
	return (head);
}
