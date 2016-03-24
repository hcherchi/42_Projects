/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:16:59 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 14:29:33 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
	t->image->data[x * t->image->bpp / 8
		+ y * t->image->size_line] = (unsigned char)color->b;
	t->image->data[x * t->image->bpp / 8
		+ 1 + y * t->image->size_line] = (unsigned char)color->g;
	t->image->data[x * t->image->bpp / 8
		+ 2 + y * t->image->size_line] = (unsigned char)color->r;
}

t_ray		*get_ray(t_tool *t, float x, float y)
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
	float	x0;
	float	y0;
	t_color	*final_color;
	t_color	*color;

	final_color = new_color();
	x0 = x;
	while (x0 <= x + 0.5)
	{
		y0 = y;
		while (y0 <= y + 0.5)
		{
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
	float		min;

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

t_color		*get_color(t_ray *ray, t_tool *t)
{
	t_object	*object;
	t_color		*final_color;
	t_ray		*impact;

	final_color = new_color();
	if ((object = intersection(t->l_objects, ray)))
	{
		init_color(t, object->color, final_color);
		impact = get_normal(object, ray);
		illuminate(t, object, impact, final_color);
		clean_ray(impact);
	}
	clean_ray(ray);
	return (final_color);
}
