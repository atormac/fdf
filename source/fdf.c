/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:12:05 by atorma            #+#    #+#             */
/*   Updated: 2024/06/19 15:28:30 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	keyhook(mlx_key_data_t key, void *param)
{
	t_fdf	*f;

	f = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(f->mlx);
		return ;
	}
	if ((key.action == MLX_PRESS) || (key.action == MLX_REPEAT))
	{
		if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
			point_rotate_color(f);
		else if (key.key == MLX_KEY_K && f->scale < 200)
		{
			f->scale += 2;
			draw_map(f);
		}
		else if (key.key == MLX_KEY_J && f->scale > 2)
		{
			f->scale -= 2;
			draw_map(f);
		}
	}
}

static int	is_in_bounds(t_matrix *matrix, int scale)
{
	if (scale * matrix->width > WIDTH / 2)
		return (0);
	if (scale * matrix->height > HEIGHT / 2)
		return (0);
	if (scale * matrix->z_max > HEIGHT / 2)
		return (0);
	return (1);
}

static void	set_scale(t_fdf *f)
{
	f->scale = 2;
	while (is_in_bounds(f->matrix, f->scale + 1))
		f->scale++;
}

int	fdf_init(t_fdf *f)
{
	f->color_opt = C_OPT_MAGENTA;
	set_scale(f);
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

void	fdf_draw(t_fdf *f)
{
	draw_map(f);
	mlx_key_hook(f->mlx, &keyhook, f);
	mlx_loop(f->mlx);
}
