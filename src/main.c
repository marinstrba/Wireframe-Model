/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 18:06:40 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"


// What i have to improve is the map input wont always have the same width

int	main(int argc, char **argv)
{
	int				fd;
	t_point			*cordinates;
	t_additional	*dataset;

	dataset = malloc (sizeof(t_additional));
	dataset->zoom = 30;
	dataset->screen_height = 600;
	dataset->screen_width = 800;
	dataset->full_screen = 0;
	dataset->shift_x = 370;
	dataset->shift_y = 150;
	dataset->color = 0xffffff;
	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		cordinates = fdf_read_map(fd, &dataset);
	else
		fdf_corrupted_file();
	dataset->data = cordinates;
	fdf_init_screen(&cordinates, dataset);
	free_data(&cordinates);
	return (EXIT_SUCCESS);
}
