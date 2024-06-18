/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:04:05 by atorma            #+#    #+#             */
/*   Updated: 2024/06/17 19:05:12 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
#include <math.h>

uint32_t	color_extract(uint32_t color)
{
	uint32_t red = (color >> 16) & 0xFF;
	uint32_t green = (color >> 8) & 0xFF;
	uint32_t blue = color & 0xFF;
	unsigned int final = 0xFF | (blue << 8) | ( green << 16) | (red << 24);

	printf("red: %x\n", red);
	printf("green: %x\n", green);
	printf("blue: %x\n", blue);
	printf("final: 0x%08x\n", final);
	return final;
}

typedef struct t_color
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
} t_color;

static void	color_init(t_color *c, uint32_t color)
{
	c->blue = (color >> 8 & 0xFF);
	c->green = (color >> 16 & 0xFF);
	c->red = (color >> 24 & 0xFF);
}

uint32_t	color_get(uint32_t start, uint32_t end, float percent)
{
	uint32_t	rgb[3];
	t_color s;
	t_color e;

	color_init(&s, start);
	color_init(&e, end);
	rgb[0] = (uint32_t)roundf((1 - percent) * s.red + percent * e.red);
	rgb[1] = (uint32_t)roundf((1 - percent) * s.green + percent * e.green);
	rgb[2] = (uint32_t)roundf((1 - percent) * s.blue + percent * e.blue);
	return 0xFF | (rgb[2] << 8) | ( rgb[1] << 16) | (rgb[0] << 24);
}
