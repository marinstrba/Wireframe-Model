/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 15:10:05 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_point			*cordinates;
	t_additional	*dataset;

	dataset = malloc (sizeof(t_additional));
	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		cordinates = fdf_read_map(fd, &dataset);
	else
		fdf_corrupted_file();
	fdf_initialize_struct(&dataset);
	dataset->data = cordinates;
	fdf_init_screen(&cordinates, dataset);
	free_data(&cordinates);
	fdf_free_dataset(&dataset);
	free(dataset);
	free(cordinates);
	return (EXIT_SUCCESS);
}
