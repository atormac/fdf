/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:19:37 by atorma            #+#    #+#             */
/*   Updated: 2024/06/11 21:26:56 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 600
#define SCALE 25

typedef struct	t_matrix
{
	int **ptr;
	int	width;
	int	height;
}	t_matrix;

typedef struct	t_fdf
{
	mlx_t		*mlx;
	mlx_image_t *img;
	t_matrix	*matrix;
}	t_fdf;

void	draw_map(t_fdf *f);
void	matrix_free(int	**p, size_t y);
int		**matrix_alloc(size_t x, size_t y);
int		matrix_fill(t_fdf *f, char *map);
void	matrix_print(t_matrix *matrix);
int		fdf_init(t_fdf *f);
void	fdf_uninit(t_fdf *f);
void	fdf_draw(t_fdf *f);
#endif
