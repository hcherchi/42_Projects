/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point *getVertical(t_tool *t, float rayAngle)
{
  t_point *inc;
  t_point *curPoint;

  inc = malloc(sizeof(*inc));
  curPoint = getFirstPointVertical(t, rayAngle);
  inc->x = (rayAngle < 90 && rayAngle > -90) ? t->cubeSize : - t->cubeSize;
  inc->y = - inc->x * tan(degreesToRadians(rayAngle));
  while (insideMap(curPoint, t) && !isWall(curPoint, t))
  {
    curPoint = getNextPointVertical(t, curPoint, inc);
  }
  return curPoint;
}

t_point *getFirstPointVertical(t_tool *t, float rayAngle)
{
  t_point *point;

  point = malloc(sizeof(*point));

  if (rayAngle < 90 && rayAngle > -90)
  {
    point->x = floor(t->pos->x / t->cubeSize) * t->cubeSize + t->cubeSize;
  }
  else
  {
    point->x = floor(t->pos->x / t->cubeSize) * t->cubeSize - 1;
  }
  point->y = t->pos->y + (t->pos->x - point->x) * tan(degreesToRadians(rayAngle));
  return point;
}

t_point *getNextPointVertical(t_tool *t, t_point *curPoint, t_point *inc)
{
  t_point *nextPoint;
  float dist;

  nextPoint = malloc(sizeof(*nextPoint));
  nextPoint->x = curPoint->x + inc->x;
  nextPoint->y = curPoint->y + inc->y;
  dist = getDist(nextPoint, t);
  return nextPoint;
}
