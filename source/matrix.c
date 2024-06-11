/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:05 by atorma            #+#    #+#             */
/*   Updated: 2024/06/11 21:27:47 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_free(int	**p, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		free(p[i]);
		i--;
	}
	free(p);
}

int	**matrix_alloc(size_t x, size_t y)
{
	int		**p;
	size_t	i;

	p = ft_calloc(1, y * sizeof(int));
	if (!p)
		return (NULL);
	i = 0;
	while (i < y)
	{
		p[i] = ft_calloc(1, x * sizeof(int));
		if (!p[i])
		{
			i--;
			matrix_free(p, i);
			return (NULL);
		}
		i++;
	}
	return (p);
}
