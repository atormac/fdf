/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:05 by atorma            #+#    #+#             */
/*   Updated: 2024/06/17 16:45:19 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void	matrix_free(int	**p, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

int	**matrix_alloc(size_t x, size_t y)
{
	int		**p;
	size_t	i;

	p = ft_calloc(1, y * sizeof(int*));
	if (!p)
		return (NULL);
	i = 0;
	while (i < y)
	{
		p[i] = ft_calloc(1, x * sizeof(int));
		if (!p[i])
		{
			matrix_free(p, i);
			return (NULL);
		}
		i++;
	}
	return (p);
}

void	matrix_fill_color(char *token, t_matrix *colors, int y, int x)
{
	char		*str;
	uint32_t	color;

	str = ft_strchr(token, ',');
	if (!str)
		return ;
	str++;
	color = strtoul(str, NULL, 16);
	colors->ptr[y][x] = color;
	printf("color_hex: %lu\n", (unsigned long)colors->ptr[y][x]);	
}

void	matrix_fill_line(char *line, int y, t_matrix *matrix, t_matrix *colors)
{
	int		x;
	char	*token;
	char	*save_ptr;
	int		absolute;

	x = 0;
	token = ft_strtok_r(line, " ", &save_ptr);
	while (token != NULL)
	{
		matrix->ptr[y][x] = ft_atoi(token);
		matrix_fill_color(token, colors, y, x);
		absolute = abs(matrix->ptr[y][x]);
		if (y == 0 && x == 0)
			matrix->z_max = absolute;
		else if (absolute > matrix->z_max)
			matrix->z_max = absolute;
		token = ft_strtok_r(NULL, " ", &save_ptr);
		x++;
	}
}

int		matrix_fill(t_fdf *f, char *map)
{
	int		y;
	char	*save_ptr;
	char	*line;

	y = 0;
	save_ptr = NULL;
	line = ft_strtok_r(map, "\n", &save_ptr);
	while (line != NULL)
	{
		matrix_fill_line(line, y, f->matrix, f->colors);
		line = ft_strtok_r(NULL, "\n", &save_ptr);
		y++;
	}
	return (1);
}

void	matrix_print(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			printf("%d ", matrix->ptr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
