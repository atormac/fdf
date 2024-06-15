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

static int	map_line_count(char	*str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}

static int	map_line_len(char	*str)
{
	int	count;

	count = 1;
	while (*str && *str != '\n')
	{
		if (*str == ' ')
		{
			while (*str == ' ')
				str++;
			count++;
		}
		str++;
	}
	return (count);
}

static void	matrix_init(t_fdf *f, char *map)
{
	int	width;
	int	height;

	height = map_line_count(map);
	width = map_line_len(map);
	printf("height: %d, width: %d\n", height, width);
	f->matrix->height = height;
	f->matrix->width = width;
	f->matrix->ptr = matrix_alloc(width, height);
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
	printf("map:\n%s\n", file_data);
	matrix_init(f, file_data);
	if (!f->matrix->ptr)
	{
		free(file_data);
		return (0);
	}
	matrix_fill(f, file_data);
	free(file_data);
	return (1);
}
