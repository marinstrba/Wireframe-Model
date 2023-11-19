/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:50:24 by mstrba            #+#    #+#             */
/*   Updated: 2023/10/30 09:37:47 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *str, int character)
{
	const char	*res;

	res = str;
	while (*res)
	{
		if (*res == (char)character)
			return ((char *)res);
		res++;
	}
	if (character == '\0')
		return ((char *)res);
	return (NULL);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	unsigned char	*res;
	size_t			index;
	size_t			total;

	index = 0;
	total = num_elements * element_size;
	res = (unsigned char *) malloc(total);
	if (res == NULL)
		return (NULL);
	while (index < total)
	{
		res[index] = 0;
		index++;
	}
	return ((void *)res);
}

char	*ft_strdup(char *str)
{
	char		*res;
	size_t		length;
	size_t		index;

	index = 0;
	length = ft_strlen(str);
	res = (char *) malloc (sizeof(char) * length + 1);
	if (res == NULL)
		return (NULL);
	while (index < length)
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (*s1)
	{
		res[index] = *s1;
		s1++;
		index++;
	}
	while (*s2)
	{
		res[index] = *s2;
		s2++;
		index++;
	}
	res[index] = '\0';
	return (res);
}
