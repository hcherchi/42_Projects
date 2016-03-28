/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:16:59 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/28 12:36:19 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <stdio.h>

void		pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
	t->image->data[x * t->image->bpp / 8
		+ y * t->image->size_line] = (unsigned char)color->b;
	t->image->data[x * t->image->bpp / 8
		+ 1 + y * t->image->size_line] = (unsigned char)color->g;
	t->image->data[x * t->image->bpp / 8
		+ 2 + y * t->image->size_line] = (unsigned char)color->r;
}

void		draw(t_tool *t, int x, int y)
{
	t_ray	*ray;
	double	x0;
	double	y0;
	t_color	*final_color;
	t_color	*color;

	final_color = new_color();
	x0 = x;
	while (x0 <= x + 0.5)
	{
		y0 = y;
		while (y0 <= y + 0.5)
		{
            t->depth = 0;
			ray = get_ray(t, x0, y0);
			color = get_color(ray, t);
			add_color(final_color, color);
			free(color);
			y0 += 0.5;
		}
		x0 += 0.5;
	}
	div_color(final_color, 4);
	normalize_color(final_color);
	pixel_put_to_image(t, x, y, final_color);
	free(final_color);
}

t_color     *get_final_color(t_colors   *colors, t_object *object)
{
    t_color *final_color;
    
    if (object == NULL)
        return (colors->base);
    final_color = new_color();
    if (colors->reflect)
    {
        div_color(colors->reflect, 1 / object->mirror);
        add_color(final_color, colors->reflect);
    }
    if (colors->refract)
    {
        div_color(colors->refract, 1 / object->transp);
        add_color(final_color, colors->refract);
    }
    div_color(colors->base, 1 / (1 - object->mirror - object->transp));
    add_color(final_color, colors->base);
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
    return (extract_color(t, t->sky, x, y));
}

t_color		*get_color(t_ray *ray, t_tool *t)
{
	t_object	*object;
	t_ray		*impact;
    t_colors    *colors;

    colors = new_colors();
	if ((object = intersection(t->l_objects, ray)))
	{
        impact = get_normal(object, ray);
        colors->base = get_base_color(t, object, impact);
		if (object->mirror && t->depth < 10)
            colors->reflect = get_color(get_reflectray(ray, t, impact), t);
        if (object->transp)
            colors->refract = get_color(get_refractray(ray, impact, object), t);
        return (get_final_color(colors, object));
	}
    else
        return (new_color());
}
