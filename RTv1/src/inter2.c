/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:59 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 21:49:08 by bgantelm         ###   ########.fr       */
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

void		fill_dist(t_object *l_objects, t_ray *ray)
{
	t_object	*tmp;

	tmp = l_objects;
	while (tmp != NULL)
	{
		if (tmp->type == SPHERE)
			tmp->dist = intersection_sphere(tmp, ray);
		else if (tmp->type == CONE)
			tmp->dist = intersection_cone(tmp, ray);
		else if (tmp->type == PLAN)
			tmp->dist = intersection_plan(tmp->d, tmp->h, ray->o, ray->d);
		else if (tmp->type == CYL)
			tmp->dist = intersection_cyl(tmp, ray);
		else if (tmp->type == PARA)
			tmp->dist = intersection_para(tmp, ray);
		tmp = tmp->next;
	}
}

double		calcul_cone(t_object *cone, t_ray *ray, double k, t_pos *tmp)
{
	t_equation	param;

	param.b = 2 * (ray->d->x * tmp->x + (ray->d->y)
				* tmp->y + ray->d->z * tmp->z)
				- (2 * (cone->d->x * ray->d->x
				+ cone->d->y * ray->d->y + cone->d->z
				* ray->d->z)
				* (cone->d->x * tmp->x + cone->d->y * tmp->y
				+ cone->d->z * tmp->z))
				- (2 * (cone->d->x * ray->d->x + cone->d->y
				* ray->d->y + cone->d->z
				* ray->d->z) * (cone->d->x * tmp->x
				+ cone->d->y * tmp->y
				+ cone->d->z * tmp->z) * k);
	return (param.b);
}
