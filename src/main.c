/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/21 19:37:22 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/LIBFT/libft.h"
#include "../lib/minilibx-linux/mlx.h"

void	print_cordinates(t_point *cordinates)
{
    t_point *current = cordinates;
    int i = 0;
    while (current)
	{
        printf("Coordinates of element %d: X = %d, Y = %d, Z = %d\n", 
               i++, current->x_map, current->y_map, current->z_map);
        current = current->next;
	}
}


int	main(int argc, char **argv)
{
	int		fd;
	t_point	*map_coordinates;

	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		map_coordinates = fdf_read_map(fd);
	else
		fdf_corrupted_file();
	print_cordinates(map_coordinates);
	map_coordinates->mlx_ptr = mlx_init();
	map_coordinates->win_ptr = mlx_new_window(map_coordinates->mlx_ptr, 1000, 1000, "FDF");
	fdf_bresenham_algorithm();
	free_map_coordinates(&map_coordinates);
	return (EXIT_SUCCESS);
}
