/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:25:57 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/26 11:45:43 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_pos	*vectornew(double x, double y, double z)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_pos	*vectorcopy(t_pos *v1)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x;
	result->y = v1->y;
	result->z = v1->z;
	return (result);
}

void	vectornorm(t_pos *v)
{
	double	tmp;

	tmp = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * tmp;
	v->y = v->y * tmp;
	v->z = v->z * tmp;
}

t_pos	*rotation(t_pos *axe, t_pos *vect)
{
	t_pos	*rota_matrice;

	rota_matrice = malloc(sizeof(t_pos));
	rota_matrice->x = -vect->x + 2 * vect->x * pow(axe->x, 2)
	+ 2 * vect->y * axe->x * axe->y + 2 * vect->z * axe->x * axe->z;
	rota_matrice->y = -vect->y + 2 * vect->x * axe->x * axe->y
	+ 2 * vect->y * pow(axe->y, 2) + vect->z * 2 * axe->y * axe->z;
	rota_matrice->z = -vect->z + 2 * vect->x * axe->x * axe->z
	+ 2 * vect->y * axe->y * axe->z + 2 * vect->z * pow(axe->z, 2);
	vectornorm(rota_matrice);
	return (rota_matrice);
}
