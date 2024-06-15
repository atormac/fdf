#include "../include/fdf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	t_fdf		f;
	t_matrix	matrix;

	f.matrix = &matrix;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <map_file> !\n", STDERR_FILENO);
		return (0);
	}
	if (!map_to_matrix(argv[1], &f))
	{
		ft_putstr_fd("Failed to read map!\n", STDERR_FILENO);
		return (0);
	}
	if (!fdf_init(&f))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (0);
	}
	fdf_draw(&f);
	fdf_uninit(&f);
	matrix_free(matrix.ptr, matrix.height);
	return (0);
}
