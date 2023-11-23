/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:58 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/22 15:04:01 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#define KEY_ESC 65307 // This is typically the keycode for ESC on X11 systems


// void	print_cordinates(t_point *cordinates)
// {
//     t_point *current = cordinates;
//     int i = 0;
//     while (current != NULL)
// 	{
//         printf("Cordinates of element %d: X = %d, Y = %d, Z = %d\n", 
//                i++, current->x_map, current->y_map, current->z_map);
//         current = current->next;
// 	}
// }


int	key_press(int keycode, t_additional *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window(t_additional *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_point			*cordinates;
	t_additional	*dataset;

	dataset = malloc (sizeof(t_additional));
	dataset->zoom = 30;
	if (argc != 2)
		fdf_diff_num_of_args();
	fd = fdf_open_file(argv);
	if (fd != -1)
		cordinates = fdf_read_map(fd, &dataset);
	else
		fdf_corrupted_file();
	// printf("HEIGHT AND WIDTH %d %d\n", dataset->height, dataset->width);
	// print_cordinates(cordinates);
	// printf("WTF\n");
	//INIT OF SCREEN
	dataset->mlx_ptr = mlx_init();
	dataset->win_ptr = mlx_new_window(dataset->mlx_ptr, 1000, 1000, "FDF");
	//DRAW
	fdf_draw(cordinates, dataset);
	//KEYS
	mlx_key_hook(dataset->win_ptr, key_press, dataset);
	mlx_hook(dataset->win_ptr, 17, 0, close_window, dataset);
	//LOOP
	mlx_loop(dataset->mlx_ptr);
	//FREE DATA
	free_data(&cordinates);
	return (EXIT_SUCCESS);
}
