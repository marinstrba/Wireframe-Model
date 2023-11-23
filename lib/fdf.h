/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:39:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/23 18:37:42 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*--------------------Key definitions--------------------*/

# define KEY_ESC 65307
# define KEY_F 102
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363


/*---------------------Standart libs---------------------*/

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "LIBFT/libft.h"
# include "minilibx-linux/mlx.h"

/*---------------------Structs--------------------------*/

typedef struct s_point
{
	int				x_map;
	int				y_map;
	int				z_map;
	struct s_point	*next;
}		t_point;

typedef struct s_additional
{
	int				height;
	int				width;
	int				zoom;
	int				color;
	int				shift_y;
	int				shift_x;
	int				screen_height;
	int				screen_width;
	int				full_screen;
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			*data;
}		t_additional;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
}		t_line;

/*----------------------Open files----------------------*/

int		fdf_open_file(char	**argv);

/*-------------------Error messages---------------------*/

void	fdf_failed_malloc(void);
void	fdf_corrupted_file(void);
void	fdf_diff_num_of_args(void);

/*-----------------------Read map-----------------------*/

t_point	*fdf_read_map(int fd, t_additional	**dataset);
void	convert_cordinates(char	*line, t_point	**head, int y);

/*------------------------Screen------------------------*/

void	fdf_init_screen(t_point	**cordinates, t_additional	*dataset);

/*///////////////////DRAWING FUNCTIONS//////////////////*/

/*------------------------Draw--------------------------*/
void	fdf_draw(t_point	*data, t_additional	*dataset);

/*------------------------Menu---------------------------*/
void	fdf_print_menu(t_additional	*dataset);

/*-----------------------Rotation-----------------------*/
void	isometric(int	*x, int	*y, int z);

/*-----------------------Colors-----------------------*/

int		get_elevation_color(int z, int minZ, int maxZ);
void	find_min_max_z(t_point *head, int *minZ, int *maxZ);

/*///////////////////////UTILS///////////////////////////*/

/*-----------------------Lists---------------------------*/
void	fdf_add_node(t_point	**new_node);
void	fdf_add_node_last(t_point	*head, t_point	*node);

/*-----------------------Memory-------------------------*/

void	free_data(t_point **map_coordinates);

/*/////////////////////CONTROLS//////////////////////////*/

/*------------------------Keys-------------------------*/

int		fdf_controls_mouse_scroll(int mousecode, int x, int y, t_additional *dataset);
int		fdf_controls_key_press(int keycode, t_additional *data);
int		close_window(t_additional *data);

#endif