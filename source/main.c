#include "../include/fdf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	line_count(char	*str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}

int	line_len(char	*str)
{
	int	count;

	count = 1;
	while (*str && *str != '\n')
	{
		if (*str == ' ')
		{
			while (*str == ' ')
				str++;
			count++;
		}
		str++;
	}
	return (count);
}

void	matrix_init(t_fdf *f, char *map)
{
	int	width;
	int	height;

	height = line_count(map);
	width = line_len(map);
	printf("height: %d, width: %d\n", height, width);
	f->matrix->height = height;
	f->matrix->width = width;
	f->matrix->ptr = matrix_alloc(width, height);
}

int	map_to_matrix(char	*file, t_fdf *f)
{
	int		fd;
	int		out;
	char	*file_data;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	file_data = read_file(fd, 1024, &out);
	close(fd);
	if (!file_data)
		return (0);
	printf("map:\n%s\n", file_data);
	matrix_init(f, file_data);
	matrix_fill(f, file_data);
	free(file_data);
	return (1);
}

int main(int argc, char **argv)
{
	t_fdf		f;
	t_matrix	matrix;

	f.matrix = &matrix;
	if (argc != 2)
		return (0);
	map_to_matrix(argv[1], &f);
	matrix_print(f.matrix);
	if (!fdf_init(&f))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (0);
	}
	fdf_draw(&f);

	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	fdf_uninit(&f);
	return (0);
}
