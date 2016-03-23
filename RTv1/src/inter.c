/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:21:04 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 14:40:15 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	fill_dist(t_object *l_objects, t_ray *ray)
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
			tmp->dist = intersection_plan(tmp, ray);
		else if (tmp->type == CYL)
			tmp->dist = intersection_cyl(tmp, ray);
		tmp = tmp->next;
	}
}

float	intersection_plan(t_object *plan, t_ray *ray)
{
	float	a;
	float	b;

	a = plan->d->x * ray->d->x + plan->d->y * ray->d->y
		+ plan->d->z * ray->d->z;
	b = plan->d->x * ray->o->x + plan->d->y * ray->o->y
		+ plan->d->z * ray->o->z + plan->h;
	if (-b / a > E)
		return (-b / a);
	return (-1);
}

float	intersection_sphere(t_object *sphere, t_ray *ray)
{
	t_equation	param;
	t_pos		*dist;

	dist = vectorsub(ray->o, sphere->o);
	param.a = vectordot(ray->d, ray->d);
	param.b = 2 * vectordot(ray->d, dist);
	param.c = vectordot(dist, dist) - (sphere->rad * sphere->rad);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (-1);
	return (param.t0);
}

float	intersection_cone(t_object *cone, t_ray *ray)
{
	float		k;
	t_equation	param;

	k = pow(cone->rad / cone->h, 2);
	param.a = pow(ray->d->x, 2) + pow(ray->d->z, 2) - pow(ray->d->y, 2) * k;
	param.b = 2 * (ray->d->x * (ray->o->x - cone->o->x)
			+ ray->d->z * (ray->o->z - cone->o->z)
			- ray->d->y * (ray->o->y - cone->o->y) * k);
	param.c = pow((ray->o->x - cone->o->x), 2)
		+ pow((ray->o->z - cone->o->z), 2)
		- pow((ray->o->y - cone->o->y), 2) * k;
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (-1);
	return (param.t0);
}

float	intersection_cyl(t_object *cyl, t_ray *ray)
{
	t_equation	param;
	float		k;
	t_pos		*tmp;

	tmp = vectorsub(ray->o, cyl->o);
	k = pow(cyl->d->x, 2) + pow(cyl->d->y, 2) + pow(cyl->d->z, 2);
	param.a = vectordot(ray->d, ray->d) - (pow(cyl->d->x * ray->d->x
	+ cyl->d->y * ray->d->y + cyl->d->z * ray->d->z, 2) / k);
	param.b = 2 * (ray->d->x * tmp->x + (ray->d->y) * tmp->y + ray->d->z
	* tmp->z) - (2 * (cyl->d->x * ray->d->x + cyl->d->y * ray->d->y
	+ cyl->d->z * ray->d->z) * (cyl->d->x * tmp->x + cyl->d->y
	* tmp->y + cyl->d->z * tmp->z) / k);
	param.c = tmp->x * tmp->x + tmp->y * tmp->y + tmp->z * tmp->z - (cyl->rad
	* cyl->rad) - (pow(cyl->d->x * tmp->x + cyl->d->y * tmp->y
	+ cyl->d->z * tmp->z, 2) / k);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (-1);
	return (param.t0);
}
