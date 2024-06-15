#include "../include/fdf.h"
#include <math.h>
#include <stdio.h>

int	coord(t_fdf *f, int x)
{
	x *= SCALE;
	x -= (f->matrix->width / 2) * SCALE;
	x += f->mlx->width / 2;
	return (x);
}

int	coord_y(t_fdf *f, int y)
{
	y *= SCALE;
	y -= (f->matrix->height / 2) * SCALE;
	y += f->mlx->height / 2;
	return (y);
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

void	bersenhem_line(t_fdf *f, int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  while (1)
  {
	draw_pixel(f, x0, y0, 0xFFFFFF);
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

void  isometric(int *x, int *y, int z)
{
	 int tmp;

	 tmp = *x;
	 *x = (tmp - *y) * cos(0.523599);
	 *y = (tmp + *y) * sin(0.523599) - z;
}

void	draw_line(t_fdf *f, int x0, int y0, int x1, int y1)
{
	int	x;
	int	y;
	int	xe;
	int	ye;
	int	z;

	z = f->matrix->ptr[y0][y0];
	printf("z: %d\n", z);
	//isometric(&x0, &y0, z); 
	//sometric(&x1, &y1, z);
	x = coord(f, x0);
	y = coord_y(f, y0);
	xe = coord(f, x1);
	ye = coord_y(f, y1);
	printf("point from: %d, %d\n", x, y);
	printf("point to: %d, %d\n", xe, ye);
	bersenhem_line(f, x, y, xe, ye);
}

void	draw_map(t_fdf *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < f->matrix->height - 1)
	{
		x = 0;
		while (x < f->matrix->width - 1)
		{
			draw_line(f, x, y, x + 1, y);
			draw_line(f, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
