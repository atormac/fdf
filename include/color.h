/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:39:14 by atorma            #+#    #+#             */
/*   Updated: 2024/06/19 15:34:07 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

# define COLOR_WHITE 0xffffffff
# define COLOR_GREEN 0x00ff00ff
# define COLOR_YELLOW 0xffff00ff
# define COLOR_PURPLE 0xff00ffff

typedef struct t_color
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
}	t_color;

uint32_t	color_extract(uint32_t color);
uint32_t	color_get(uint32_t start, uint32_t end, double percent);

#endif
