/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:21:43 by atorma            #+#    #+#             */
/*   Updated: 2024/06/15 18:22:12 by atorma           ###   ########.fr       */
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
	point->z *= SCALE / 15;
	isometric(point);
	point->x += f->mlx->width / 3;
	point->y += f->mlx->height / 3;
}

void	draw_pixel(t_fdf *f, int x, int y, uint32_t color)
{
	/*uint32_t	color;

	if (f->matrix->ptr[y][x] == 0)
		color = 0xFFFFFF;
	else
		color = 0xff0000;
		*/
	mlx_put_pixel(f->img, x, y, color);
}

void	bersenhem_line(t_fdf *f, int x0, int y0, int x1, int y1, uint32_t color)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  while (1)
  {
	draw_pixel(f, x0, y0, color);
    if (x0 == x1 && y0 == y1)
		break;
    e2 = 2 * err;
	/* e_xy+e_x > 0 */
    if (e2 >= dy)
	{ 
		err += dy;
		x0 += sx;
	}
	/* e_xy+e_y < 0 */
    if (e2 <= dx) 
	{ 
		err += dx; 
		y0 += sy;
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
	if (point0.z != 0)
		color = 0x43ff64d9;

	bersenhem_line(f, point0.x, point0.y, point1.x, point1.y, color);
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
