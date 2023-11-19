/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 20:25:24 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	main(int argc, char	**argv)
{
	int	fd;
	int	**map_coordinates;

	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		map_coordinates = fdf_read_map(fd);
	else
		fdf_corrupted_file();
	for (int i = 0; i < 2; ++i)
	{
		printf("This is X cordinate >> %d", map_coordinates[i][0]);
		printf("This is Y cordinate >> %d", map_coordinates[i][1]);
		printf("This is Z cordinate >> %d", map_coordinates[i][2]);
	}
	return (EXIT_SUCCESS);
}
