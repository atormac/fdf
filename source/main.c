#include "../include/fdf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}


int main(int argc, char **argv)
{
	t_fdf		f;

	(void)argv;
	if (argc != 2)
		return (0);
	if (!fdf_init(&f))
	{
		ft_error();
		return (0);
	}
	fdf_draw(&f);

	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	fdf_uninit(&f);
	return (0);
}
