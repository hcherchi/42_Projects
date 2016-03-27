/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:00:15 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/26 11:44:58 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_ray	*get_lightray(t_ray *impact, t_light *light)
{
	t_ray	*lightray;

	lightray = malloc(sizeof(t_ray));
	lightray->o = vectorcopy(light->o);
	lightray->d = vectorsub(impact->o, lightray->o);
	vectornorm(lightray->d);
	return (lightray);
}

double	get_kdiff(t_ray *lightray, t_ray *impact, double kdist, double intens)
{
	double	kdiff;
	t_pos	*invlight;

	invlight = vectorscale(-1, lightray->d);
	kdiff = vectordot(invlight, impact->d);
	free(invlight);
	return (kdiff * kdist * intens);
}

double	get_kspec(t_ray *lightray, t_ray *impact, double kdist, double intens)
{
	double	kspec;
	t_pos	*invlight;
	t_pos	*reflectray;

	invlight = vectorscale(-1, lightray->d);
	reflectray = rotation(impact->d, invlight);
	vectornorm(reflectray);
	kspec = vectordot(invlight, reflectray);
	free(invlight);
	return (pow(kspec, 21) * kdist * intens);
}

void	illuminate(t_tool *t, t_object *obj, t_ray *imp, t_color *f_color)
{
	t_light		*light;
	t_ray		*lightray;
	t_object	*obj2;
	t_k			k;

	light = t->l_lights;
	while (light)
	{
		lightray = get_lightray(imp, light);
		if ((obj2 = intersection(t->l_objects, lightray)) && (obj2 == obj))
		{
			k.dist = MAX((light->dist - obj->dist) / light->dist, 0);
			k.diff = get_kdiff(lightray, imp, k.dist, light->lumdiff);
			if (k.diff >= 0)
			{
				update_color(k.diff , light->color, f_color, obj->color);
				k.spec = get_kspec(lightray, imp, k.dist, light->lumdiff);
				if (k.spec >= 0)
					update_color(k.spec * obj->shiny,
							light->color, f_color, obj->color);
			}
		}
		clean_ray(lightray);
		light = light->next;
	}
}

void	update_color(double k, t_color *lightco, t_color *f_c, t_color *objcol)
{
	f_c->r += (lightco->r + 3 * objcol->r) / 4 * k;
	f_c->g += (lightco->g + 3 * objcol->g) / 4 * k;
	f_c->b += (lightco->b + 3 * objcol->b) / 4 * k;
}
