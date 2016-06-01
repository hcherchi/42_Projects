/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:55 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 22:18:51 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double	intersection_plan(t_pos *d, double h, t_pos *oray, t_pos *dray)
{
	double	a;
	double	b;

	a = d->x * dray->x + d->y * dray->y
		+ d->z * dray->z;
	b = d->x * oray->x + d->y * oray->y
		+ d->z * oray->z + h;
	if (-b / a > E)
		return (-b / a);
	return (-1);
}

double	intersection_sphere(t_object *sphere, t_ray *ray)
{
	t_equation	param;
	t_pos		*dist;

	dist = vectorsub(ray->o, sphere->o);
	param.a = vectordot(ray->d, ray->d);
	param.b = 2 * vectordot(ray->d, dist);
	param.c = vectordot(dist, dist) - (sphere->rad * sphere->rad);
	free(dist);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (param.t0 > param.t1)
		param.t0 = param.t1;
	if (param.t0 < E)
		return (-1);
	return (param.t0);
}

double	intersection_para(t_object *para, t_ray *ray)
{
	t_equation	param;

	param.a = pow(ray->d->x, 2) + pow(ray->d->z, 2);
	param.b = 2 * (ray->d->x * (ray->o->x - para->o->x)
			+ ray->d->z * (ray->o->z - para->o->z)
			- para->h * ray->d->y);
	param.c = pow((ray->o->x - para->o->x), 2)
		+ pow((ray->o->z - para->o->z), 2)
		- 2 * para->h * (ray->o->y - para->o->y);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (param.t0 > param.t1)
		param.t0 = param.t1;
	if (param.t0 < E)
		return (-1);
	return (param.t0);
}

double	intersection_cyl(t_object *cyl, t_ray *ray)
{
	t_equation	param;
	double		k;
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
	if (param.t0 > param.t1)
		param.t0 = param.t1;
	if (param.t0 < E)
		return (-1);
	return (param.t0);
}

double	intersection_cone(t_object *cone, t_ray *ray)
{
	double		k;
	t_equation	param;
	t_pos		*tmp;

	tmp = vectorsub(ray->o, cone->o);
	k = pow(cone->rad / cone->h, 2);
	param.a = vectordot(ray->d, ray->d) - pow(cone->d->x * ray->d->x
	+ cone->d->y * ray->d->y + cone->d->z * ray->d->z, 2)
	- pow(cone->d->x * ray->d->x + cone->d->y * ray->d->y
	+ cone->d->z * ray->d->z, 2) * k;
	param.b = calcul_cone(cone, ray, k, tmp);
	param.c = tmp->x * tmp->x + tmp->z * tmp->z + tmp->y * tmp->y
	- pow(cone->d->x * tmp->x + cone->d->y * tmp->y + cone->d->z
	* tmp->z, 2) - pow(cone->d->x * tmp->x + cone->d->y * tmp->y
	+ cone->d->z * tmp->z, 2) * k;
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (-1);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < E)
		return (-1);
	return (param.t0);
}
