/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:07:04 by bgantelm          #+#    #+#             */
/*   Updated: 2016/03/21 11:18:37 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rtv1.h>

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
	light->O = malloc(sizeof(t_pos));
	light->color = malloc(sizeof(t_color));
	light->O->x = 0;
	light->O->y = 0;
	light->O->z = 0;
	light->color->r = 0;
	light->color->g = 0;
	light->color->b = 0;
	light->dist = 0;
}

void	init_object(t_object *object)
{
	object->O = malloc(sizeof(t_pos));
	object->D = malloc(sizeof(t_pos));
	object->color = malloc(sizeof(t_color));
	object->O->x = 0;
	object->O->y = 0;
	object->O->z = 0;
	object->D->x = 0;
	object->D->y = 0;
	object->D->z = 0;
	object->color->r = 0;
	object->color->g = 0;
	object->color->b = 0;
	object->type = 3;
	object->rad = 0;
	object->h = 0;
	object->shiny = 0;
}
