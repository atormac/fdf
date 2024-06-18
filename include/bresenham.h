#ifndef BRESENHAM_H
# define BRESENHAM_H

typedef struct t_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

void	bresenham(t_fdf *f, struct t_point point0, struct t_point point1);

#endif
