/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:51:51 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:08:17 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	clean_colors(t_colors **colors)
{
	if ((*colors)->base)
	{
		free((*colors)->base);
		(*colors)->base = NULL;
	}
	if ((*colors)->refract)
	{
		free((*colors)->refract);
		(*colors)->refract = NULL;
	}
	if ((*colors)->reflect)
	{
		free((*colors)->reflect);
		(*colors)->reflect = NULL;
	}
	if (*colors)
	{
		free(*colors);
		*colors = NULL;
	}
}

void	clean_cams(t_cam ***cams, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		clean_cam(&(*cams)[i]);
		i++;
	}
}

void	clean_cam(t_cam **cam)
{
	if ((*cam)->pos)
		free((*cam)->pos);
	if ((*cam)->vect)
		free((*cam)->vect);
	if ((*cam)->h_vect)
	{
		free((*cam)->h_vect);
		(*cam)->h_vect = NULL;
	}
	if ((*cam)->r_vect)
	{
		free((*cam)->r_vect);
		(*cam)->r_vect = NULL;
	}
	if ((*cam)->upleft)
	{
		free((*cam)->upleft);
		(*cam)->upleft = NULL;
	}
	if (*cam)
	{
		free(*cam);
		*cam = NULL;
	}
}

void	clean_lights(t_light **l_lights)
{
	t_light	*tmp;

	while (*l_lights)
	{
		tmp = *l_lights;
		*l_lights = (*l_lights)->next;
		if (tmp->color)
			free(tmp->color);
		if (tmp->o)
		{
			free(tmp->o);
			tmp->o = NULL;
		}
		if (tmp->d)
		{
			free(tmp->d);
			tmp->d = NULL;
		}
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
}

void	clean_obj(t_object **l_objects)
{
	t_object	*tmp;

	while (*l_objects)
	{
		tmp = *l_objects;
		*l_objects = (*l_objects)->next;
		if (tmp->color)
			free(tmp->color);
		if (tmp->o)
			free(tmp->o);
		if (tmp->d)
		{
			free(tmp->d);
			tmp->d = NULL;
		}
		if (tmp->texture)
			clean_image(&tmp->texture);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
}
