/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/21 21:44:40 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#define KEY_ESC 65307 // This is typically the keycode for ESC on X11 systems

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


int	key_press(int keycode, t_point *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window(t_point *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * TASKS:
 * Make a new library.
 * 		-> This library will include get_next_line and also ft_printf
*/

int	main(int argc, char **argv)
{
	int		fd;
	t_point	*data;

	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		data = fdf_read_map(fd);
	else
		fdf_corrupted_file();
	print_cordinates(data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	
	fdf_draw(data);

	mlx_key_hook(data->win_ptr, key_press, data);

	mlx_hook(data->win_ptr, 17, 0, close_window, data);

	mlx_loop(data->mlx_ptr);
	
	free_data(&data);
	return (EXIT_SUCCESS);
}
