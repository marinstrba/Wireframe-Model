/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 11:27:26 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	main(int argc, char **argv)
{
	int				fd;
	int				scw;
	int				sch;
	t_point			*cordinates;
	t_additional	*dataset;

	dataset = malloc (sizeof(t_additional));
	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		cordinates = fdf_read_map(fd, &dataset);
	else
	{
		free_data(&cordinates);
		free(dataset);
		fdf_corrupted_file();
	}
	fdf_initialize_struct(&dataset);
	dataset->data = cordinates;
	scw = dataset->screen_width;
	sch = dataset->screen_height;
	dataset->mlx_ptr = mlx_init();
	dataset->win_ptr = mlx_new_window(dataset->mlx_ptr, scw, sch, "Wireframe");
	fdf_new_image(dataset);
	fdf_init_screen(&cordinates, dataset);
	return (EXIT_SUCCESS);
}
