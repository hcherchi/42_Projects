/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:40 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:45:20 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double	get_kdiff(t_ray *lightray, t_ray *impact, double lumdiff)
{
	double	kdiff;
	t_pos	*invlight;

	invlight = vectorscale(-1, lightray->d);
	kdiff = vectordot(invlight, impact->d);
	free(invlight);
	return (kdiff * lumdiff);
}

double	get_kspec(t_ray *lightray, t_ray *impact, double lumdiff)
{
	double	kspec;
	t_pos	*invlight;
	t_pos	*reflectray;

	invlight = vectorscale(-1, lightray->d);
	reflectray = vectoradd(vectorscale(-2 * vectordot(lightray->d,
	impact->d), impact->d), lightray->d);
	vectornorm(reflectray);
	kspec = vectordot(invlight, reflectray);
	free(invlight);
	free(reflectray);
	return (pow(kspec, 21) * lumdiff);
}

double	get_ray_intens(t_tool *t, t_ray *lightray, t_object *obj)
{
	t_object	*curobj;
	double		intens;

	intens = 1;
	curobj = t->rt->l_objects;
	fill_dist(curobj, lightray);
	while (curobj)
	{
		if (curobj->dist != -1 && curobj->dist < obj->dist)
			intens -= (1 - curobj->transp);
		curobj = curobj->next;
	}
	return (intens);
}

void	get_base_color(t_tool *t, t_object *obj, t_ray *impact, t_colors *col)
{
	t_light		*light;
	t_ray		*lightray;
	t_k			*k;

	k = malloc(sizeof(*k));
	if (obj->texture)
		obj->color = get_texture_color(obj, impact, t);
	light = t->rt->l_lights;
	while (light)
	{
		if ((lightray = get_lightray(impact, light)))
		{
			k->intens = get_ray_intens(t, lightray, obj);
			k->diff = get_kdiff(lightray, impact, k->intens * light->lumdiff);
			if (k->diff >= 0)
			{
				update_color(k->diff, light->color, col->base, obj->color);
				k->s = get_kspec(lightray, impact, k->intens * light->lumdiff);
				if (k->s >= 0)
					update_color(k->s * obj->shiny, light->color,
					col->base, obj->color);
			}
		}
		light = light->next;
	}
}

void	update_color(double k, t_color *lcol, t_color *col, t_color *objcol)
{
	col->r += (lcol->r + 3 * objcol->r) / 4 * k;
	col->g += (lcol->g + 3 * objcol->g) / 4 * k;
	col->b += (lcol->b + 3 * objcol->b) / 4 * k;
}
