/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/28 11:24:18 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/fdf.h"

void	fdf_draw_down(t_point	*ptr1, t_point	*ptr2, t_additional	*data)
{
	t_point	*draw_down_ptr;
	int		index;

	draw_down_ptr = ptr1;
	index = 0;
	while (index < data->width)
	{
		draw_down_ptr = draw_down_ptr->next;
		index++;
	}
	index = 0;
	while (index < data->width)
	{
		fdf_bresenham(ptr1, draw_down_ptr, data);
		draw_down_ptr = draw_down_ptr->next;
		ptr1 = ptr1->next;
		index++;
	}
	ptr2 = ptr2;
}

void	fdf_draw(t_point	*data, t_additional	*dataset)
{
	t_point	*ptr1;
	t_point	*ptr2;
	t_point	*ptr3;
	int		index;

	ptr1 = data;
	ptr2 = data;
	index = 0;
	while (ptr1->next != NULL)
	{
		ptr3 = ptr1;
		while (ptr2->next != NULL && ptr2->next->y_map == ptr1->y_map)
		{
			ptr2 = ptr2->next;
			fdf_bresenham(ptr1, ptr2, dataset);
			ptr1 = ptr2;
		}
		ptr1 = ptr3;
		if (index++ == (dataset->height - 1))
			break ;
		fdf_draw_down(ptr1, ptr2, dataset);
		ptr2 = ptr2->next;
		ptr1 = ptr2;
	}
}
