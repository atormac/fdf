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

void	matrix_free(int	**p, size_t y);
int		**matrix_alloc(size_t x, size_t y);

#endif
