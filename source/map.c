/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:45:22 by atorma            #+#    #+#             */
/*   Updated: 2024/06/15 19:52:41 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <stdio.h>

static int	map_width(char	*str)
{
	char	*end;
	int		count;

	end = ft_strchr(str, '\n');
	if (!end)
		return (0);
	str[end - str] = '\0';
	count = ft_count_words(str, ' ');
	str[end - str] = '\n';
	return (count);
}

static int matrix_init(t_fdf *f, char *map)
{
	int	width;
	int	height;

	height = ft_count_words(map, '\n');
	width = map_width(map);
	if (height <= 0 || width <= 0)
		return (0);
	printf("height: %d, width: %d\n", height, width);
	printf("map:\n%s\n", map);
	f->matrix->height = height;
	f->matrix->width = width;
	f->matrix->ptr = matrix_alloc(width, height);
	if (!f->matrix->ptr)
		return (0);
	return (1);
}

int	map_to_matrix(char	*file, t_fdf *f)
{
	int		fd;
	int		out;
	char	*file_data;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	file_data = read_file(fd, 1024, &out);
	close(fd);
	if (!file_data)
		return (0);
	if (!matrix_init(f, file_data))
	{
		free(file_data);
		return (0);
	}
	matrix_fill(f, file_data);
	free(file_data);
	return (1);
}
