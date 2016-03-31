#include <rtv1.h>
#include <stdio.h>

void		pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
    if(t->screen_shot == 0)
    {
        t->image->data[x * t->image->bpp / 8 + y * t->image->size_line] = (unsigned char)color->b;
        t->image->data[x * t->image->bpp / 8 + 1 + y * t->image->size_line] = (unsigned char)color->g;
        t->image->data[x * t->image->bpp / 8 + 2 + y * t->image->size_line] = (unsigned char)color->r;
    }
    else
    {
        t->image->screen[(x + y * t->x_res)*3 + 0] = (unsigned char) color->r;
        t->image->screen[(x + y * t->x_res)*3 + 1] = (unsigned char) color->g;
        t->image->screen[(x + y * t->x_res)*3 + 2] = (unsigned char) color->b;
    }
}

// ANTI ALIASING ET POSE D'UN PIXEL

void		draw(t_tool *t, int x, int y)
{
	t_ray	*ray;
	double	x0;
	double	y0;
	t_color	*moy_color;
	t_color	*color;

	moy_color = new_color();
	x0 = x;
	while (x0 <= x + 0.5)
	{
		y0 = y;
		while (y0 <= y + 0.5)
		{
            t->depth = 0;
			ray = get_ray(t, x0, y0);
			color = get_color(ray, t);
			moy_color = add_color(moy_color, color);
			free(color);
			y0 += 0.5;
		}
		x0 += 0.5;
	}
	moy_color = div_color(moy_color, 4);
	normalize_color(moy_color);
	pixel_put_to_image(t, x, y, moy_color);
	free(moy_color);
}

t_color     *get_final_color(t_colors   *colors, t_object *object)
{
    t_color *final_color;
	double	kbase;

	kbase = 1 - object->mirror - object->transp;
    final_color = new_color();
    if (colors->reflect)
        final_color = add_color(final_color, mult_color(colors->reflect, object->mirror));
    if (colors->refract)
        final_color = add_color(final_color, mult_color(colors->refract, object->transp));
    final_color = add_color(final_color, mult_color(colors->base, kbase));
    clean_colors(colors);
    return (final_color);
}

t_color     *get_sky_color(t_ray *ray, t_tool *t)
{
    t_pos *impact;
    double      x;
    double      y;
    
    impact = malloc(sizeof(t_pos));
    impact = vectoradd(ray->o, vectorscale(100, ray->d));
    vectornorm(impact);
    x = (0.5 + (atan2(impact->z, impact->x) / (2 * M_PI))) * t->sky->width;
    y = (0.5 - asin(impact->y) / M_PI) * t->sky->height;
    free(impact);
    return (extract_color(t, t->sky, x, y));
}

// RECUPER LES 3 COULEURS : BASE REFLETEE REFRACTEE

t_color		*get_color(t_ray *ray, t_tool *t)
{
	t_object	*object;
	t_ray		*impact;
    t_colors    *colors;
    t_color     *final_color;

	if ((object = intersection(t->l_objects, ray)))
	{
        colors = new_colors();
        impact = get_normal(object, ray);
        colors->base = get_base_color(t, object, impact);
		if (object->mirror && t->depth < 4)
            colors->reflect = get_color(get_reflectray(ray, t, impact), t);
        if (object->transp)
            colors->refract = get_color(get_refractray(ray, impact, object), t);
        clean_ray(impact);
        final_color = get_final_color(colors, object);
        return (final_color);
	}
    else
    {
        if (t->sky)
            final_color = get_sky_color(ray, t);
        else
            final_color = new_color();
    }
    clean_ray(ray);
    return (final_color);
}
