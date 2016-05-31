/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:59 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 19:54:00 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double		minimum(t_object *l_objects)
{
	double	min;

	min = 200000;
	while (l_objects != NULL)
	{
		if (l_objects->dist != -1 && l_objects->dist < min)
			min = l_objects->dist;
		l_objects = l_objects->next;
	}
	return (min);
}

t_object	*intersection(t_object *l_objects, t_ray *ray)
{
	t_object	*tmp;
	double		min;

	fill_dist(l_objects, ray);
	tmp = l_objects;
	min = minimum(tmp);
	if (min == 200000)
		return (NULL);
	while (tmp != NULL)
	{
		if (tmp->dist == min)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
