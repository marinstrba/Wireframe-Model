/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:39:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 20:05:49 by mstrba           ###   ########.fr       */
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

/*-------------------Error messages---------------------*/

void	fdf_failed_malloc(void);
void	fdf_corrupted_file(void);
void	fdf_diff_num_of_args(void);

/*----------------------Open files----------------------*/

int		fdf_open_file(char	**argv);

/*-----------------------Read map-----------------------*/

int		**fdf_read_map(int fd);
void	fdf_reallocate_cordinates(int	***cordinates, int *bytes_allocated);
void	convert_to_cordinates(int	***cordinates, char	*line, int y_cordinate);


#endif