/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:37:12 by hcherchi          #+#    #+#             */
/*   Updated: 2016/06/01 10:37:13 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double		get_flash_intens(t_tool *t, t_ray *ray, double lightdist)
{
	t_object	*curobj;
	double		intens;

	intens = 1;
	curobj = t->rt->l_objects;
	fill_dist(curobj, ray);
	while (curobj)
	{
		if (curobj->dist != -1 && curobj->dist < lightdist)
			intens -= (1 - curobj->transp);
		curobj = curobj->next;
	}
	if (intens < 0)
		intens = 0;
	return (intens);
}

void		get_1_flash(t_color **flash, t_light *light, t_ray *ray, t_tool *t)
{
	double	angle;
	double	intens;
	double	lightdist;
	t_ray	*flashray;

	flashray = malloc(sizeof(t_ray));
	flashray->o = vectorcopy(t->rt->cam->pos);
	if (light->type == SUN || light->type == SPOT)
	{
		flashray->d = vectorsub(light->o, ray->o);
		vectornorm(flashray->d);
	}
	else if (light->type == LIGHTPLAN)
		flashray->d = vectorscale(-1, light->d);
	angle = vectordot(flashray->d, ray->d);
	lightdist = sqrtf(pow(light->o->x - t->rt->cam->pos->x, 2) +
			pow(light->o->y - t->rt->cam->pos->y, 2) +
			pow(light->o->z - t->rt->cam->pos->z, 2));
	intens = get_flash_intens(t, ray, lightdist);
	if (angle > 0 && ((light->type == SPOT &&
	vectordot(vectorscale(-1, flashray->d), light->d) > light->angle)
	|| light->type != SPOT))
		*flash = add_color(*flash, mult_color(light->color,
		pow(angle, 30) * intens * light->lumdiff));
	clean_ray(&flashray);
}

t_color		*get_flash(t_ray *ray, t_tool *t)
{
	t_light		*light;
	t_color		*flash;

	flash = new_color();
	light = t->rt->l_lights;
	while (light)
	{
		get_1_flash(&flash, light, ray, t);
		light = light->next;
	}
	return (flash);
}
