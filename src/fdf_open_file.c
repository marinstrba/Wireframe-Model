/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:15:01 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 18:34:55 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include "../lib/GNL/get_next_line.h"

int	fdf_open_file(char	**argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	return (fd);
}
