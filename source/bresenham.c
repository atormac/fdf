#include "../include/fdf.h"
#include "../include/color.h"
#include "../include/bresenham.h"

static double	calc_per(int start, int end, int current)
{
	double	cur;
	double	total;

	cur = current - start;
	total = end - start;
	if (total == 0)
		return (1.0);
	return (cur / total);
}

static double	update(t_bresenham *b, t_point *p0, t_point *p1, int *start)
{
	double	per;
	int		start_x;
	int		start_y;

	start_x = start[0];
	start_y = start[1];
	b->e2 = 2 * b->err;
	if (b->e2 >= b->dy)
	{
		b->err += b->dy;
		p0->x += b->sx;
		per = calc_per(start_x, p1->x, p0->x);
	}
	else if (b->e2 <= b->dx)
	{
		b->err += b->dx;
		p0->y += b->sy;
		per = calc_per(start_y, p1->y, p0->y);
	}
	return (per);
}

void	bresenham(t_fdf *f, struct t_point point0, struct t_point point1)
{
	t_bresenham	b;
	int			start[2];
	double		per;
	uint32_t	gradient;

	start[0] = point0.x;
	start[1] = point0.y;
	per = 0.0;
	b.dx = abs(point1.x - point0.x);
	b.dy = -abs(point1.y - point0.y);
	b.sx = -1;
	b.sy = -1;
	if (point0.x < point1.x)
		b.sx = 1;
	if (point0.y < point1.y)
		b.sy = 1;
	b.err = b.dx + b.dy;
	while (1)
	{
		gradient = color_get(point0.color, point1.color, per);
		draw_pixel(f, point0.x, point0.y, gradient);
		if (point0.x == point1.x && point0.y == point1.y)
			break ;
		per = update(&b, &point0, &point1, start);
	}
}
