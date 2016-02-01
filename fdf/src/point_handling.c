/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:57:13 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 11:44:55 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point(t_point *a, int cx, int cy, float angle)
{
	float s;
	float c;
	float newx;
	float newy;

	s = sin(angle);
	c = cos(angle);
	a->x -= cx;
	a->y -= cy;
	newx = a->x * c - a->y * s;
	newy = a->x * s + a->y * c;
	a->x = newx + cx;
	a->y = newy + cy;
}

t_point	*create_point(t_tool *t, int i, int j)
{
	float	k;
	t_point	*point;
	int		range;

	range = t->zmax - t->zmin;
	if (range <= 20)
		t->coef_alti = 8;
	else
		t->coef_alti = 1.0 / 4.0;
	point = malloc(sizeof(t_point *));
	k = (float)(t->wwin) / (float)t->nbcol;
	point->x = j * k;
	point->y = i * k;
	rotate_point(point, 0, 0, 0.2);
	point->y /= 1.4;
	if (t->wmax && t->wmin && t->hmin && t->hmax)
	{
		point->y += 700 - t->hmax->y + (t->hmax->y - t->hmin->y) / 2;
		point->x += 1280 - t->wmax->x + (t->wmax->x - t->wmin->x) / 2;
	}
	point->z = t->tab[i][j];
	point->y -= t->tab[i][j] * t->coef_alti;
	return (point);
}

void	set_points(t_tool *tools)
{
	int i;
	int j;

	find_min_max(tools);
	tools->points = malloc(sizeof(t_point**) * tools->nbline);
	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		tools->points[i] = malloc(sizeof(t_point*) * tools->nbcol);
		while (j < tools->nbcol)
		{
			tools->points[i][j] = create_point(tools, i, j);
			j++;
		}
		i++;
	}
}
