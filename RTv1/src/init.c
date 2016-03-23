/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:20:40 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/22 17:20:58 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	init_camera(t_tool *tools)
{
	tools->cam->pos = malloc(sizeof(t_pos));
	tools->cam->pos->x = 0;
	tools->cam->pos->y = 0;
	tools->cam->pos->z = 0;
	tools->cam->x_res = 1000;
	tools->cam->y_res = 800;
}

void	init_light(t_light *light)
{
	light->o = malloc(sizeof(t_pos));
	light->color = malloc(sizeof(t_color));
	light->o->x = 0;
	light->o->y = 0;
	light->o->z = 0;
	light->color->r = 0;
	light->color->g = 0;
	light->color->b = 0;
	light->dist = 0;
}

void	init_object(t_object *object)
{
	object->o = malloc(sizeof(t_pos));
	object->d = malloc(sizeof(t_pos));
	object->color = malloc(sizeof(t_color));
	object->o->x = 0;
	object->o->y = 0;
	object->o->z = 0;
	object->d->x = 0;
	object->d->y = 0;
	object->d->z = 0;
	object->color->r = 0;
	object->color->g = 0;
	object->color->b = 0;
	object->type = 3;
	object->rad = 0;
	object->h = 0;
	object->shiny = 0;
}
