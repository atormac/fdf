#include "../include/fdf.h"

void	draw_pixel(t_fdf *f, int y, int x)
{
	uint32_t	color;

	if (f->matrix->ptr[y][x] == 0)
		color = 0xFFFFFF;
	else
		color = 0xff0000;
	x *= ZOOM;
	y *= ZOOM;
	x -= (f->matrix->width / 2) * ZOOM;
	y -= (f->matrix->height / 2) * ZOOM;
	x += f->mlx->width / 2;
	y += f->mlx->height / 2;
	mlx_put_pixel(f->img, x, y, color);
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
			draw_pixel(f, y, x);
			x++;
		}
		y++;
	}
}
