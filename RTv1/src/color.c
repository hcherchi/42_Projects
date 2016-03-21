#include <Rtv1.h>

void	init_color(t_tool *t, t_color *objcolor, t_color *final_color)
{
	final_color->r = objcolor->r * t->LumAmb;
	final_color->g = objcolor->g * t->LumAmb;
	final_color->b = objcolor->b * t->LumAmb;
}

void	normalize_color(t_color *final_color)
{
	if (final_color->r < 0)
		final_color->r = 0;
	if (final_color->b < 0)
		final_color->b = 0;
	if (final_color->g < 0)
		final_color->g = 0;
	if (final_color->r > 255)
		final_color->r = 255;
	if (final_color->b > 255)
		final_color->b = 255;
	if (final_color->g > 255)
		final_color->g = 255;
}

void	add_color(t_color *color1, t_color *color2)
{
	color1->r += color2->r;
	color1->g += color2->g;
	color1->b += color2->b;
}

void	div_color(t_color *color, float n)
{
	color->r /= n;
	color->g /= n;
	color->b /= n;
}

t_color	*new_color(void)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
