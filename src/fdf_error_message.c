/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:09:02 by mstrba            #+#    #+#             */
/*   Updated: 2023/11/19 18:22:57 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	fdf_diff_num_of_args(void)
{
	write(1, "Wrong number of arguments. Try again.\n", 38);
}

void	fdf_corrupted_file(void)
{
	write(1, "The file u provided is corrupted.", 33);
}
