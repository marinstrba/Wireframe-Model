/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:39:15 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 18:20:21 by mstrba           ###   ########.fr       */
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

void		fdf_diff_num_of_args(void);

/*Open files*/

int			fdf_open_file(char	**argv);

#endif