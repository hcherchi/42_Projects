/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/05 15:12:36 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	get_horizontal_dist(t_tool *t, float ray_angle)
{
	t_point	*inc;
	t_point	*cur_point;
	float	dist;

	inc = malloc(sizeof(*inc));
	cur_point = get_first_point_horizontal(t, ray_angle);
	inc->y = is_up_part(ray_angle) ? -t->cube : +t->cube;
	inc->x = -inc->y / tan(D_TO_R(ray_angle));
	while (inside_map(cur_point, t) && !is_wall(cur_point, t))
	{
		free(cur_point);
		cur_point = get_next_point_horizontal(t, cur_point, inc);
	}
	free(inc);
	dist = get_dist(cur_point, t);
	free(cur_point);
	return (dist);
}

t_point	*get_first_point_horizontal(t_tool *t, float ray_angle)
{
	t_point	*point;

	point = malloc(sizeof(*point));
	if (is_up_part(ray_angle))
		point->y = floor(t->pos->y / t->cube) * t->cube - E;
	else
		point->y = floor(t->pos->y / t->cube) * t->cube + t->cube;
	point->x = t->pos->x + (t->pos->y - point->y) / tan(D_TO_R(ray_angle));
	return (point);
}

t_point	*get_next_point_horizontal(t_tool *t, t_point *cur_point, t_point *inc)
{
	t_point	*next_point;
	float	dist;

	next_point = malloc(sizeof(*next_point));
	next_point->x = cur_point->x + inc->x;
	next_point->y = cur_point->y + inc->y;
	dist = get_dist(next_point, t);
	return (next_point);
}
