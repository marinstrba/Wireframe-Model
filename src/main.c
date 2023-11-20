/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/20 12:30:54 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void print_cordinates(int **cordinates, int total_elements) {
    if (cordinates == NULL) {
        printf("No coordinates to print.\n");
        return;
    }

    for (int i = 0; i < total_elements; ++i) {
        if (cordinates[i] != NULL) {
            printf("Coordinates of element %d: X = %d, Y = %d, Z = %d\n", 
                   i, cordinates[i][0], cordinates[i][1], cordinates[i][2]);
        } else {
            printf("Coordinates of element %d: NULL\n", i);
        }
    }
}

void free_map_coordinates(int ***map_coordinates, int total_elements) {
    if (map_coordinates == NULL || *map_coordinates == NULL) {
        return; // Nothing to free
    }

    for (int i = 0; i < total_elements; ++i) {
        free((*map_coordinates)[i]); // Free each sub-array
    }

    free(*map_coordinates); // Free the array of pointers
    *map_coordinates = NULL; // Set the pointer to NULL to prevent use-after-free
}


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
	print_cordinates(map_coordinates, 4);
	free_map_coordinates(&map_coordinates, 3);
	return (EXIT_SUCCESS);
}
