/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:58:28 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 22:47:56 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	init_light(t_light *light)
{
	light->o = malloc(sizeof(t_pos));
	light->d = malloc(sizeof(t_pos));
	light->color = malloc(sizeof(t_color));
	light->type = SUN;
	light->o->x = 1;
	light->o->y = 1;
	light->o->z = 0;
	light->d->x = 0;
	light->d->y = -1;
	light->d->z = 0;
	light->h = 10;
	light->angle = M_PI / 6;
	light->color->r = 255;
	light->color->g = 255;
	light->color->b = 255;
	light->lumdiff = 1;
	light->next = NULL;
}

void	init_object(t_object *object)
{
	object->o = malloc(sizeof(t_pos));
	object->d = malloc(sizeof(t_pos));
	object->color = malloc(sizeof(t_color));
	object->texture = NULL;
	object->o->x = 0;
	object->o->y = 0;
	object->o->z = 3;
	object->d->x = 0;
	object->d->y = 1;
	object->d->z = 0;
	object->color->r = 255;
	object->color->g = 255;
	object->color->b = 255;
	object->type = SPHERE;
	object->rad = 0.5;
	object->h = 1;
	object->shiny = 0;
	object->refract = 1.02;
	object->mirror = 0;
	object->transp = 0;
	object->next = NULL;
}

void	init_camera(t_tool *tools)
{
	tools->rt->lumamb = 0.1;
	tools->rt->x_res = 1000;
	tools->rt->y_res = 800;
	tools->rt->sky = NULL;
	tools->rt->vect = NULL;
	tools->rt->pos = NULL;
	tools->rt->image = NULL;
	tools->rt->cam = NULL;
	tools->rt->up = NULL;
	tools->rt->mid = NULL;
}
