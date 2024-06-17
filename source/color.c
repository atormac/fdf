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

