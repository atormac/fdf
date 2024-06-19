/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:05 by atorma            #+#    #+#             */
/*   Updated: 2024/06/19 14:57:21 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>

void	matrix_free(int	**p, size_t y)
{
	size_t	i;

	i = 0;
	if (!p)
		return ;
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

	p = ft_calloc(1, y * sizeof(int *));
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
	if (ft_strlen(str) < 2)
		return ;
	str += 3;
	color = ft_atoi_base(str, "0123456789ABCDEF");
	colors->ptr[y][x] = color;
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

int	matrix_fill(t_fdf *f, char *map)
{
	int		y;
	char	*save_ptr;
	char	*line;

	y = 0;
	save_ptr = NULL;
	if (f->matrix->height != (int)ft_count_words(map, '\n'))
		return (0);
	line = ft_strtok_r(map, "\n", &save_ptr);
	while (line != NULL)
	{
		if (f->matrix->width != (int)ft_count_words(line, ' '))
			return (0);
		matrix_fill_line(line, y, f->matrix, f->colors);
		line = ft_strtok_r(NULL, "\n", &save_ptr);
		y++;
	}
	return (1);
}
