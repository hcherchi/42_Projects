/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:14:49 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 10:15:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	clean_ray(t_ray *ray)
{
	free(ray->o);
	free(ray->d);
	ray->o = NULL;
	ray->d = NULL;
	free(ray);
	ray = NULL;
}

void	clean_tools(t_tool *tools)
{
	free(tools->image->data);
	free(tools->image);
	free(tools->mlx_ptr);
	free(tools->mlx_img);
	free(tools->mlx_win);
	clean_cam(tools->cam);
	clean_obj(tools->l_objects);
	clean_lights(tools->l_lights);
}

void	clean_cam(t_cam *cam)
{
	free(cam->pos);
	free(cam->vect);
	free(cam->h_vect);
	free(cam->r_vect);
	free(cam->upleft);
	free(cam);
}

void	clean_lights(t_light *l_lights)
{
	t_light	*tmp;

	while (l_lights)
	{
		tmp = l_lights;
		l_lights = l_lights->next;
		free(tmp->color);
		free(tmp->o);
		free(tmp);
	}
}

void	clean_obj(t_object *l_objects)
{
	t_object	*tmp;

	while (l_objects)
	{
		tmp = l_objects;
		l_objects = l_objects->next;
		free(tmp->color);
		free(tmp->o);
		free(tmp->d);
		free(tmp);
	}
}
