/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int   isUpPart(float angle)
{
  if (angle > 0 && angle <= 180)
    return 1;
  else
    return 0;
}

int isRightPart(float angle)
{
  if ((angle >= 0 && angle < 90) || (angle < 360 && angle >= 270))
    return 1;
  else
    return 0;
}

int   isWall(t_point *intersection, t_tool *t)
{
  int i;
  int j;

  i = intersection->y / t->cubeSize;
  j = intersection->x / t->cubeSize;
  if (t->grid[i][j] == 1)
    return 1;
  else
    return 0;
}

int   insideMap(t_point *intersection, t_tool *t)
{
  int i;
  int j;

  i = intersection->y / t->cubeSize;
  j = intersection->x / t->cubeSize;
  if (i < t->nbline && i >= 0 && j < t->nbcol && j >= 0)
    return 1;
  else
    return 0;
}

float getDist(t_point *wall, t_tool *t)
{
  return (sqrt(pow(t->pos->x - wall->x, 2) + pow(t->pos->y - wall->y, 2)));
}
