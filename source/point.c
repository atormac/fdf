/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:53 by atorma            #+#    #+#             */
/*   Updated: 2024/06/19 14:31:55 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/color.h"
#include <math.h>

static void	isometric(t_point *point)
{
	int	tmp;

	tmp = point->x;
	point->x = (tmp - point->y) * cos(0.523599);
	point->y = (tmp + point->y) * sin(0.523599) - point->z;
}

void	point_init(t_fdf *f, t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
	point->z = f->matrix->ptr[y][x];
}

void	point_scale(t_fdf *f, t_point *point)
{
	point->x *= f->scale;
	point->y *= f->scale;
	point->z *= f->scale;
	isometric(point);
	point->x += WIDTH / 2;
	point->y += HEIGHT / 2;
}

void	point_set_color(t_fdf *f, t_point *point)
{
	uint32_t	col_matrix;

	point->color = COLOR_WHITE;
	if (point->z != 0)
		point->color = COLOR_PURPLE;
	col_matrix = (uint32_t)f->colors->ptr[point->y][point->x];
	if (col_matrix != 0)
		point->color = color_extract(col_matrix);
}
