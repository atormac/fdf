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
	mlx_t* mlx;
	mlx_image_t *img;

	f = param;
	mlx = f->mlx;
	img = f->img;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(mlx);
		return ;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		img->instances[0].y -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		img->instances[0].y += 10;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		img->instances[0].x -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		img->instances[0].x += 10;
}

int	fdf_init(t_fdf *f)
{
	f->mlx = mlx_init(1024, 1024, "FdF", true);
	if (!f->mlx)
		return (0);
	f->img = mlx_new_image(f->mlx, 256, 256);
	if (!f->img)
		return (0);
	ft_memset(f->img->pixels, 255, f->img->width * f->img->height * sizeof(int));
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (0);
	return (1);
}

void	fdf_uninit(t_fdf *f)
{
	mlx_terminate(f->mlx);
}

void	fdf_draw(t_fdf *f)
{
	mlx_key_hook(f->mlx, &keyhook, f);
	mlx_loop_hook(f->mlx, ft_hook, f->mlx);
	mlx_loop(f->mlx);
}

