/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:21:43 by atorma            #+#    #+#             */
/*   Updated: 2024/06/15 18:43:13 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>
#include <stdio.h>

void  isometric(t_point *point)
{
	 int tmp;

	 tmp = point->x;
	 point->x = (tmp - point->y) * cos(0.523599);
	 point->y = (tmp + point->y) * sin(0.523599) - point->z;
}

void	point_scale(t_fdf *f, t_point *point)
{
	point->x *= SCALE;
	point->y *= SCALE;
	point->z *= SCALE / (SCALE / 2);
	isometric(point);
	point->x += f->mlx->width / 3;
	point->y += f->mlx->height / 3;
}

void	draw_pixel(t_fdf *f, int x, int y, uint32_t color)
{
	mlx_put_pixel(f->img, x, y, color);
}

void	plot_line(t_fdf *f, struct t_point point0, struct t_point point1, uint32_t color)
{
  int	dx;
  int	dy;
  int	sx;
  int	sy;
  int	err;
  int	e2;

  dx =  abs (point1.x - point0.x);
  dy = -abs (point1.y - point0.y);
  sx = point0.x < point1.x ? 1 : -1;
  sy = point0.y < point1.y ? 1 : -1;
  err = dx + dy;
  while (1)
  {
	draw_pixel(f, point0.x, point0.y, color);
    if (point0.x == point1.x && point0.y == point1.y)
		break;
    e2 = 2 * err;
	/* e_xy+e_x > 0 */
    if (e2 >= dy)
	{ 
		err += dy;
		point0.x += sx;
	}
	/* e_xy+e_y < 0 */
    if (e2 <= dx) 
	{ 
		err += dx; 
		point0.y += sy;
	}
  }
}


void	draw_line(t_fdf *f, int x0, int y0, int x1, int y1)
{
	uint32_t		color;
	t_point	point0;
	t_point	point1;

	point0.x = x0;
	point0.y = y0;
	point0.z = f->matrix->ptr[y0][x0];
	point1.x = x1;
	point1.y = y1;
	point1.z = f->matrix->ptr[y1][x1];
	point_scale(f, &point0);
	point_scale(f, &point1);
	color = 0xfffafa;
	if (point0.z != 0 || point1.z != 0)
		color = 0x43ff64d9;

	plot_line(f, point0, point1, color);
}

void	draw_map(t_fdf *f)
{
	int	x;
	int	y;

	y = 0;
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
