/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:49:34 by bgantelm          #+#    #+#             */
/*   Updated: 2016/06/01 10:49:36 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_ray	*get_normal(t_object *object, t_ray *ray)
{
	t_ray	*impact;

	impact = malloc(sizeof(t_ray));
	impact->o = vectoradd(ray->o, vectorscale(object->dist, ray->d));
	if (object->type == SPHERE)
		impact->d = vectorsub(impact->o, object->o);
	else if (object->type == PLAN)
		impact->d = vectorcopy(object->d);
	else if (object->type == CONE)
		get_cone_normal(impact, object);
	else if (object->type == CYL)
		get_cyl_normal(impact, object);
	else if (object->type == PARA)
		get_para_normal(impact, object);
	vectornorm(impact->d);
	return (impact);
}

void	get_cyl_normal(t_ray *impact, t_object *object)
{
	impact->d = malloc(sizeof(t_pos));
	impact->d->x = 2 * (impact->o->x - object->o->x) - (2 * object->d->x
			* (object->d->x * (impact->o->x - object->o->x) + object->d->z
				* (impact->o->z - object->o->z) + object->d->y * (impact->o->y
					- object->o->y)))
		/ (pow(object->d->z, 2) + pow(object->d->y, 2)
				+ pow(object->d->x, 2));
	impact->d->y = 2 * (impact->o->y - object->o->y) - (2 * object->d->y
			* (object->d->x * (impact->o->x - object->o->x) + object->d->z
				* (impact->o->z - object->o->z) + object->d->y * (impact->o->y
					- object->o->y)))
		/ (pow(object->d->z, 2) + pow(object->d->y, 2)
				+ pow(object->d->x, 2));
	impact->d->z = 2 * (impact->o->z - object->o->z) - (2 * object->d->z
			* (object->d->x * (impact->o->x - object->o->x) + object->d->z
				* (impact->o->z - object->o->z) + object->d->y * (impact->o->y
					- object->o->y)))
		/ (pow(object->d->z, 2) + pow(object->d->y, 2)
				+ pow(object->d->x, 2));
}

void	get_cone_normal(t_ray *impact, t_object *object)
{
	double	k;

	impact->d = malloc(sizeof(t_pos));
	k = pow(object->rad / object->h, 2);
	impact->d->x = 2 * (impact->o->x - object->o->x)
		- (2 * object->d->x * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)))
		- (k * 2 * object->d->x * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)));
	impact->d->y = 2 * (impact->o->y - object->o->y)
		- (2 * object->d->y * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)))
		- (k * 2 * object->d->y * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)));
	impact->d->z = 2 * (impact->o->z - object->o->z)
		- (2 * object->d->z * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)))
		- (k * 2 * object->d->z * (object->d->x * (impact->o->x - object->o->x)
		+ object->d->z * (impact->o->z - object->o->z)
		+ object->d->y * (impact->o->y - object->o->y)));
}

void	get_para_normal(t_ray *impact, t_object *object)
{
	impact->d = malloc(sizeof(t_pos));
	impact->d->x = impact->o->x - object->o->x;
	impact->d->y = -object->h;
	impact->d->z = impact->o->z - object->o->z;
}
