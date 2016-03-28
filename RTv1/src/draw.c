/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:16:59 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/26 11:44:50 by hcherchi         ###   ########.fr       */
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

t_ray		*get_ray(t_tool *t, double x, double y)
{
	t_ray	*ray;
	t_pos	*tmp;

	ray = malloc(sizeof(t_ray));
	ray->o = malloc(sizeof(t_pos));
	tmp = malloc(sizeof(t_pos));
	ray->o->x = t->cam->pos->x;
	ray->o->y = t->cam->pos->y;
	ray->o->z = t->cam->pos->z;
	tmp->x = t->cam->upleft->x + t->cam->r_vect->x * t->cam->indent * x
		- t->cam->h_vect->x * t->cam->indent * y;
	tmp->y = t->cam->upleft->y + t->cam->r_vect->y * t->cam->indent * x
		- t->cam->h_vect->y * t->cam->indent * y;
	tmp->z = t->cam->upleft->z + t->cam->r_vect->z * t->cam->indent * x
		- t->cam->h_vect->z * t->cam->indent * y;
	ray->d = vectorsub(tmp, ray->o);
	vectornorm(ray->d);
	return (ray);
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

t_object	*intersection(t_object *l_objects, t_ray *ray)
{
	t_object	*tmp;
	double		min;

	fill_dist(l_objects, ray);
	tmp = l_objects;
	min = minimum(tmp);
	if (min == 200000)
		return (NULL);
	while (tmp != NULL)
	{
		if (tmp->dist == min)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
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

t_color *    extract_color(t_tool *t, int x, int y)
{
    t_color *c;
    int color;
    unsigned int lcolor;
    
    color = t->texture->data[x * t->texture->bpp / 8 + y * t->texture->size_line];
    color += t->texture->data[x * t->texture->bpp / 8 + 1 + y * t->texture->size_line] * 256;
    color += t->texture->data[x * t->texture->bpp / 8 + 2 + y * t->texture->size_line] * 256 * 256;
    lcolor = mlx_get_color_value(t->mlx_ptr, color);
    c = new_color();
    c->r = ((lcolor & 0xFF0000) >> 16);
    c->g = ((lcolor & 0xFF00) >> 8);
    c->b = ((lcolor & 0xFF));
    return (c);
}

t_color     *get_texture_color(t_object *object, t_pos *impact, t_tool *t)
{
    double x;
    double y;
    t_color *color;
//    double  tmp;
//    int     div;
//    
//    x = impact->x / 0.002;
//    y = -impact->z / 0.002;
//    
//    tmp = y / t->texture->height;
//    div = floor(tmp);
//    y = (tmp - div) * t->texture->height;
////    if (div % 2 != 0)
////    {
////        x += (t->texture->width / 2);
////    }
//    tmp = x / t->texture->width;
//    div = floor(tmp);
//    x = (tmp - div) * t->texture->height;
    y = asin(impact->z / object->rad);
    x = acos((impact->x / object->rad ) / acos(y));
    printf("%f, %f\n", x, y);
    color = extract_color(t, x, y);
    return (color);
}

t_color		*get_color(t_ray *ray, t_tool *t)
{
	t_object	*object;
	t_color		*final_color;
	t_ray		*impact;
    t_ray       *reflect;
    t_colors    *colors;

    colors = new_colors();
	colors->base = new_color();
	if ((object = intersection(t->l_objects, ray)))
	{
        impact = get_normal(object, ray);
        if (object->texture == 1)
        {
            object->color = get_texture_color(object, impact->o, t);
        }
		init_color(t, object->color, colors->base);
		if (object->mirror && t->depth < 10)
		{
            t->depth += 1;
            reflect = malloc(sizeof(t_ray));
            reflect->o = vectorcopy(impact->o);
            reflect->d = vectoradd(vectorscale(-2 * vectordot(ray->d, impact->d), impact->d), ray->d);
            colors->reflect = get_color(reflect, t);
		}
        if (object->transp)
        {
            ray->o = vectorcopy(impact->o);
            ray->d = vectorscale(-1, ray->d);
            ray->d = vectorsub(vectorscale(1 / object->refract * vectordot(impact->d, ray->d) - sqrtf(1 - (pow(1 / object->refract, 2) * (1 - pow(vectordot(impact->d, ray->d), 2)))), impact->d), vectorscale(1 / object->refract, ray->d));
            colors->refract = get_color(ray, t);
        }
		illuminate(t, object, impact, colors->base);
		clean_ray(impact);
	}
	//clean_ray(ray);
    final_color = get_final_color(colors, object);
	return (final_color);
}
