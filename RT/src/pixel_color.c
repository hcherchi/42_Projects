/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:49:47 by bgantelm          #+#    #+#             */
/*   Updated: 2016/06/01 13:32:09 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_color		*get_final_color(t_colors *colors, t_object *object)
{
	t_color	*final_color;
	double	kbase;

	kbase = 1 - object->mirror - object->transp;
	final_color = new_color();
	if (colors->reflect)
		final_color = add_color(final_color,
		mult_color(colors->reflect, object->mirror));
	if (colors->refract)
		final_color = add_color(final_color,
		mult_color(colors->refract, object->transp));
	final_color = add_color(final_color, mult_color(colors->base, kbase));
	clean_colors(&colors);
	return (final_color);
}

t_color		*get_sky_color(t_ray *ray, t_tool *t)
{
	t_pos		*impact;
	double		x;
	double		y;

	impact = malloc(sizeof(t_pos));
	impact = vectoradd(ray->o, vectorscale(100, ray->d));
	vectornorm(impact);
	x = (0.5 + (atan2(impact->z, impact->x) / (2 * M_PI))) *
		t->rt->sky->width - 1;
	y = (0.5 - asin(impact->y) / M_PI) * t->rt->sky->height - 1;
	free(impact);
	return (extract_color(t, t->rt->sky, x, y));
}

t_colors	*get_colors(t_object *object, t_ray *ray, t_tool *t)
{
	t_ray		*impact;
	t_colors	*colors;

	colors = new_colors();
	impact = get_normal(object, ray);
	colors->base = mult_color(object->color, t->rt->lumamb);
	get_base_color(t, object, impact, colors);
	if (object->mirror && t->rt->depth < 2)
		colors->reflect = get_color(get_reflectray(ray, t, impact), t);
	if (object->transp)
		colors->refract = get_color(get_refractray(ray, impact, object), t);
	clean_ray(&impact);
	return (colors);
}

t_color		*get_color(t_ray *ray, t_tool *t)
{
	t_object	*object;
	t_colors	*colors;
	t_color		*final_color;

	if ((object = intersection(t->rt->l_objects, ray)))
	{
		colors = get_colors(object, ray, t);
		final_color = get_final_color(colors, object);
	}
	else
	{
		if (t->rt->sky)
			final_color = get_sky_color(ray, t);
		else
			final_color = new_color();
	}
	final_color = add_color(final_color, get_flash(ray, t));
	clean_ray(&ray);
	return (final_color);
}
