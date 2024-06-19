
#ifndef COLOR_H
# define COLOR_H

#include <stdint.h>

#define COLOR_WHITE 0xffffffff
#define COLOR_PURPLE 0xff00ffff

typedef struct t_color
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
}	t_color;

uint32_t	color_extract(uint32_t color);
uint32_t	color_get(uint32_t start, uint32_t end, double percent);

#endif
