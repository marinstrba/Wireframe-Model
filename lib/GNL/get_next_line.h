/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:11 by mstrba            #+#    #+#             */
/*   Updated: 2023/10/30 09:39:03 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*--------------------StandartLibs--------------------*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*--------------------BUFFER_SIZE---------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/*--------------------get_next_line-------------------*/

char	*get_next_line(int fd);

/*-----------------get_next_line_utils----------------*/

char	*ft_strdup(char *str);
char	*ft_strchr(const char *str, int character);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num_elements, size_t element_size);

#endif
