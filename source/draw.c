/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:21:43 by atorma            #+#    #+#             */
/*   Updated: 2024/06/17 20:09:27 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/color.h"
#include <stdio.h>

void	draw_pixel(t_fdf *f, int x, int y, uint32_t color)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		mlx_put_pixel(f->img, x, y, color);
}

void	draw_line(t_fdf *f, int x0, int y0, int x1, int y1)
{
	t_point	point0;
	t_point	point1;

	point0.x = x0;
	point0.y = y0;
	point0.z = f->matrix->ptr[y0][x0];
	point1.x = x1;
	point1.y = y1;
	point1.z = f->matrix->ptr[y1][x1];
	point_set_color(f, &point0);
	point_set_color(f, &point1);
	point_scale(f, &point0);
	point_scale(f, &point1);
	bresenham(f, point0, point1);
}

void	draw_map(t_fdf *f)
{
	int	x;
	int	y;

	y = 0;
	ft_memset(f->img->pixels, 0, f->img->width * f->img->height * sizeof(int));
	while (y < f->matrix->height)
	{
		x = 0;
		while (x < f->matrix->width)
		{
			if (x != f->matrix->width - 1)
				draw_line(f, x, y, x + 1, y);
			if (y != f->matrix->height - 1)
				draw_line(f, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
