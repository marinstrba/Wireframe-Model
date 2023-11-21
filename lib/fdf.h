/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:39:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/21 19:33:50 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*---------------------Standart libs---------------------*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

/*---------------------Structs--------------------------*/

typedef struct s_point
{
	int				x_map;
	int				y_map;
	int				z_map;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_point	*next;
}		t_point;

/*-------------------Error messages---------------------*/

void	fdf_failed_malloc(void);
void	fdf_corrupted_file(void);
void	fdf_diff_num_of_args(void);

/*----------------------Open files----------------------*/

int		fdf_open_file(char	**argv);

/*-----------------------Read map-----------------------*/

t_point	*fdf_read_map(int fd);
void	convert_cordinates(char	*line, t_point	**head, int y);

/*Lists*/
void	fdf_add_node(t_point	**new_node);
void	fdf_add_node_last(t_point	*head, t_point	*node);

/*-----------------------Memory-------------------------*/

void	free_map_coordinates(t_point **map_coordinates);

#endif