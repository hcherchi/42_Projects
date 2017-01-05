/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/05 15:12:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_up_part(float angle)
{
	if (angle > 0 && angle <= 180)
		return (1);
	else
		return (0);
}

int		is_right_part(float angle)
{
	if ((angle >= 0 && angle < 90) || (angle < 360 && angle >= 270))
		return (1);
	else
		return (0);
}

int		is_wall(t_point *intersection, t_tool *t)
{
	int i;
	int j;

	i = intersection->y / t->cube;
	j = intersection->x / t->cube;
	if (t->grid[i][j] == 1)
		return (1);
	else
		return (0);
}

int		inside_map(t_point *intersection, t_tool *t)
{
	int i;
	int j;

	i = intersection->y / t->cube;
	j = intersection->x / t->cube;
	if (i < t->nbline && intersection->y >= 0 && i >= 0
		&& j < t->nbcol && intersection->x >= 0 && j >= 0)
		return (1);
	else
		return (0);
}

float	get_dist(t_point *wall, t_tool *t)
{
	return (sqrt(pow(t->pos->x - wall->x, 2) + pow(t->pos->y - wall->y, 2)));
}
