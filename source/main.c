/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:50:01 by atorma            #+#    #+#             */
/*   Updated: 2024/06/19 17:19:06 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		f;
	t_matrix	matrix;
	t_matrix	colors;

	f.matrix = &matrix;
	f.colors = &colors;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <map_file>\n", STDERR_FILENO);
		return (0);
	}
	if (!map_to_matrix(argv[1], &f))
	{
		ft_putstr_fd("Invalid map!\n", STDERR_FILENO);
		return (0);
	}
	if (fdf_init(&f))
	{
		fdf_draw(&f);
		mlx_terminate(f.mlx);
	}
	matrix_free(matrix.ptr, matrix.height);
	matrix_free(colors.ptr, matrix.height);
	return (0);
}
