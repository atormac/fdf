#include "fdf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 256
#define HEIGHT 256

static void ft_error(void)
{
		fprintf(stderr, "%s", mlx_strerror(mlx_errno));
			exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
		const mlx_t* mlx = param;

			printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int main(void)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
