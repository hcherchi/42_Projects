/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:40 by vnguyen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/05/31 22:23:26 by fhenri           ###   ########.fr       */
=======
/*   Updated: 2016/05/31 22:46:28 by hcherchi         ###   ########.fr       */
>>>>>>> ab9d5bc0f750f5232cc604703060c70a34af456f
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
	reflectray = vectoradd(vectorscale(-2 * vectordot(lightray->d, impact->d), impact->d), lightray->d);
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

t_color	*get_base_color(t_tool *t, t_object *obj, t_ray *impact)
{
	t_light		*light;
	t_ray		*lightray;
	double		kspec;
	double		kdiff;
	t_color		*base_color;
	double		intens;

	if (obj->texture)
		obj->color = get_texture_color(obj, impact, t);
	base_color = mult_color(obj->color, t->rt->lumamb);
	light = t->rt->l_lights;
	while (light)
	{
		if ((lightray = get_lightray(impact, light)))
		{
			intens = get_ray_intens(t, lightray, obj);
			kdiff = get_kdiff(lightray, impact, intens * light->lumdiff);
			if (kdiff >= 0)
			{
				update_color(kdiff, light->color, base_color, obj->color);
				kspec = get_kspec(lightray, impact, intens * light->lumdiff);
				if (kspec >= 0)
					update_color(kspec * obj->shiny, light->color, base_color, obj->color);
			}
		}
		light = light->next;
	}
	if (obj->texture)
		free(obj->color);
	return (base_color);
}

void	update_color(double k, t_color *lightcolor, t_color *color, t_color *objcolor)
{
	color->r += (lightcolor->r + 3 * objcolor->r) / 4 * k;
	color->g += (lightcolor->g + 3 * objcolor->g) / 4 * k;
	color->b += (lightcolor->b + 3 * objcolor->b) / 4 * k;
}
