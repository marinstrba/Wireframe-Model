/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:39:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 12:52:51 by mstrba           ###   ########.fr       */
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
# define YES 121
# define NO 110
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define ONE 65436
# define TWO 65433
# define THREE 65435
# define FOUR 65430

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

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	err;
	int	max_z;
	int	min_z;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}		t_line;

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
	int				do_isometric;
	int				color_low;
	int				color_high;
	void			*mlx_ptr;
	void			*win_ptr;
	t_line			*line;
	t_point			*data;
}		t_additional;

/*//////////////////////MAP-READER//////////////////////*/

t_point	*fdf_read_map(int fd, t_additional	**dataset);
void	convert_cordinates(char	*line, t_point	**head, int y);

/*///////////////////DRAWING FUNCTIONS//////////////////*/

/*------------------------Draw--------------------------*/
void	init_line_vars(t_line *line);
void	draw_line(t_line *line, t_additional *dt);
void	fdf_draw(t_point	*data, t_additional	*dataset);
void	fdf_draw_down(t_point	*ptr1, t_point	*ptr2, t_additional	*data);
void	fdf_bresenham(t_point *data, t_point	*ptr2, t_additional *dataset);
void	calc_param(t_line *line, t_point *data, t_point *ptr, t_additional *ds);

/*------------------------Menu---------------------------*/
void	fdf_print_menu(t_additional	*dataset);
void	fdf_print_controls(t_additional	*data);
void	fdf_print_map_info(t_additional	*data);
void	fdf_isometric_mode(t_additional	*data);
void	fdf_color_mode(t_additional	*data);
void	fdf_other_controls(t_additional	*data);

/*///////////////////////UTILS///////////////////////////*/

/*-----------------------Lists---------------------------*/
void	fdf_add_node(t_point	**new_node);
void	fdf_add_node_last(t_point	*head, t_point	*node);

/*-----------------------Memory-------------------------*/

void	free_data(t_point **map_coordinates);

/*-----------------------Rotation-----------------------*/
void	isometric(int	*x, int	*y, int z);
void	fdf_do_isometric(int keycode, t_additional *dataset);

/*-------------------------Others------------------------*/

void	fdf_initialize_struct(t_additional	**data);

/*-------------------Error messages---------------------*/

void	fdf_failed_malloc(void);
void	fdf_corrupted_file(void);
void	fdf_diff_num_of_args(void);

/*----------------------Open files----------------------*/

int		fdf_open_file(char	**argv);

/*///////////////////////COLORS//////////////////////////*/

/*-----------------------Colors-------------------------*/

int		lerp(int start, int end, float t);
int		get_red_component(int color);
int		get_green_component(int color);
int		get_blue_component(int color);
int		combine_colors(int r, int g, int b);
int		get_elevation_color(t_additional	*ds, int z, int minZ, int maxZ);
void	find_min_max_z(t_point *head, int *minZ, int *maxZ);

/*/////////////////////CONTROLS//////////////////////////*/

/*------------------------Screen------------------------*/

void	fdf_init_screen(t_point	**cordinates, t_additional	*data);
void	fdf_full_screen(t_additional *dataset);
void	fdf_fs_help(t_additional **dataset);
int		close_window(t_additional *data);

/*------------------------Keys-------------------------*/

int		fdf_controls_mouse(int mousecode, int x, int y, t_additional *dataset);
int		fdf_controls_key_press(int keycode, t_additional *data);
void	fdf_movement_keys(int keycode, t_additional *dataset);
void	fdf_color_mode_control(int keycode, t_additional *dataset);

#endif