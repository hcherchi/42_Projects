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
    return (pow(kspec, 21) * lumdiff);
}

double  get_ray_intens(t_tool *t, t_ray *lightray, t_object *obj)
{
    t_object *curobj;
    double  intens;
    
    intens = 1;
    curobj = t->l_objects;
    fill_dist(t->l_objects, lightray);
    while (curobj)
    {
        if (curobj->dist != -1 && curobj->dist < obj->dist)
            intens -= (1 - curobj->transp);
        curobj = curobj->next;
    }
    return (intens);
}

t_color     *get_base_color(t_tool *t, t_object *obj, t_ray *impact)
{
	t_light		*light;
    t_ray		*lightray;
    double		kspec;
    double       kdiff;
    t_color *base_color;
    double      intens;

    if (obj->texture)
        obj->color = get_texture_color(obj, impact, t);
    base_color = init_lumamb(t, obj->color);
	light = t->l_lights;
	while (light)
    {
        if ((lightray = get_lightray(impact, light)))
        {
            intens = get_ray_intens(t, lightray, obj);
            kdiff = get_kdiff(lightray, impact, intens * light->lumdiff);
            if (kdiff >= 0)
            {
                update_color(kdiff , light->color, base_color, obj->color);
                kspec = get_kspec(lightray, impact, intens * light->lumdiff);
                if (kspec >= 0)
                    update_color(kspec * obj->shiny, light->color, base_color, obj->color);
            }
        }
        light = light->next;
    }
    return (base_color);
}

void	update_color(double k, t_color *lightcolor, t_color *color, t_color *objcolor)
{
	color->r += (lightcolor->r + 3 * objcolor->r) / 4 * k;
	color->g += (lightcolor->g + 3 * objcolor->g) / 4 * k;
	color->b += (lightcolor->b + 3 * objcolor->b) / 4 * k;
}
