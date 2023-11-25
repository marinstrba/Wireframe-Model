/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:37:48 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/25 16:01:21 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_free_dataset(t_additional **dataset)
{
	if (dataset && *dataset)
	{
		if ((*dataset)->line)
		{
			free((*dataset)->line);
			(*dataset)->line = NULL;
		}
		free_data(&((*dataset)->data));
		free((*dataset)->mlx_ptr);
		free((*dataset)->win_ptr);
		free(*dataset);
		*dataset = NULL;
	}
}
