/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:32:20 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:41:19 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		calcule3(t_ray *impact, t_object *object, t_double *deux)
{
	deux->x = -impact->o->z * object->texture_zoom;
	deux->y = -impact->o->y * object->texture_zoom;
}

void		calcule2(t_ray *impact, t_object *object, t_double *deux)
{
	deux->x = impact->o->x * object->texture_zoom;
	deux->y = -impact->o->y * object->texture_zoom;
}

void		calcule1(t_ray *impact, t_object *object, t_double *deux)
{
	deux->x = impact->o->x * object->texture_zoom;
	deux->y = -impact->o->z * object->texture_zoom;
}

t_color		*extract_color(t_tool *t, t_image *texture, int x, int y)
{
	t_color			*c;
	int				color;
	unsigned int	lcolor;

	color = texture->data[x * texture->bpp / 8 + y * texture->size_line];
	color += texture->data[x * texture->bpp / 8 + 1 + y *
		texture->size_line] * 256;
	color += texture->data[x * texture->bpp / 8 + 2 + y *
		texture->size_line] * 256 * 256;
	lcolor = mlx_get_color_value(t->mlx_ptr, color);
	c = new_color();
	c->r = ((lcolor & 0xFF0000) >> 16);
	c->g = ((lcolor & 0xFF00) >> 8);
	c->b = ((lcolor & 0xFF));
	return (c);
}

t_color		*get_texture_color(t_object *object, t_ray *impact, t_tool *t)
{
	t_double deux;

	if (object->type == PLAN)
	{
		if (fabs(object->d->y) == 1)
			calcule1(impact, object, &deux);
		else if (fabs(object->d->z) == 1)
			calcule2(impact, object, &deux);
		else if (fabs(object->d->x) == 1)
			calcule3(impact, object, &deux);
		else
			return (mult_color(object->color, 1));
		texture_suite(&deux, object);
		deux.color = extract_color(t, object->texture, deux.x, deux.y);
	}
	else if (object->type == SPHERE)
	{
		deux.x = (0.5 + (atan2(impact->d->z, impact->d->x)
					/ (2 * M_PI))) * object->texture->width;
		deux.y = (0.5 - asin(impact->d->y) / M_PI) * object->texture->height;
		deux.color = extract_color(t, object->texture, deux.x, deux.y);
	}
	else
		deux.color = object->color;
	return (deux.color);
}
