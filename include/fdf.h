/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:19:37 by atorma            #+#    #+#             */
/*   Updated: 2024/06/17 19:28:22 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH	1200
#define HEIGHT	1000

typedef struct	t_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct	t_matrix
{
	int **ptr;
	int	width;
	int	height;
	int	z_max;
}	t_matrix;

typedef struct	t_fdf
{
	mlx_t		*mlx;
	mlx_image_t *img;
	t_matrix	*matrix;
	t_matrix	*colors;
	int			scale;
}	t_fdf;

void	draw_pixel(t_fdf *f, int x, int y, uint32_t color);
void	draw_map(t_fdf *f);
void	matrix_free(int	**p, size_t y);
int		**matrix_alloc(size_t x, size_t y);
int		matrix_fill(t_fdf *f, char *map);
int		map_to_matrix(char	*file, t_fdf *f);
int		fdf_init(t_fdf *f);
void	fdf_uninit(t_fdf *f);
void	fdf_draw(t_fdf *f);
void	point_init(t_fdf *f, t_point *point, int x, int y);
void	point_scale(t_fdf *f, t_point *point);
void	point_set_color(t_fdf *f, t_point *point);
#endif
