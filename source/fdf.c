#include "../include/fdf.h"
#include <stdio.h>

static void ft_hook(void* param)
{
	const mlx_t* mlx;

	mlx = param;
	(void)mlx;
//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(f->mlx);
		return ;
	}
}

int	fdf_init(t_fdf *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!f->mlx)
		return (0);
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img)
		return (0);
	ft_memset(f->img->pixels, 0, f->img->width * f->img->height * sizeof(int));
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (0);
	return (1);
}

void	fdf_uninit(t_fdf *f)
{
	mlx_terminate(f->mlx);
}

void	draw_map(t_fdf *f)
{
	int	x;
	int	y;
	int **matrix;

	y = 0;
	matrix = f->matrix->ptr;
	while (y < f->matrix->height * 10)
	{
		x = 0;
		while (x < f->matrix->width * 10)
		{
			if (matrix[y / 10][x / 10] == 0)
				mlx_put_pixel(f->img, y, x, 0xFFFFFF);
			else
				mlx_put_pixel(f->img, y, x, 0xff0000);
			x += 10;
		}
		y += 10;
	}
}
void	fdf_draw(t_fdf *f)
{
	draw_map(f);

	mlx_key_hook(f->mlx, &keyhook, f);
	mlx_loop_hook(f->mlx, ft_hook, f->mlx);
	mlx_loop(f->mlx);
}

