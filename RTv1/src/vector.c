/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:44:59 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 14:23:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_pos	*vectorsub(t_pos *v1, t_pos *v2)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
	return (result);
}

float	vectordot(t_pos *v1, t_pos *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_pos	*vectorscale(float c, t_pos *v)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v->x * c;
	result->y = v->y * c;
	result->z = v->z * c;
	return (result);
}

t_pos	*vectoradd(t_pos *v1, t_pos *v2)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
	return (result);
}
