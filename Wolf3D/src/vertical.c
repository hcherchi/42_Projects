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

float   getVerticalDist(t_tool *t, float rayAngle)
{
  t_point *inc;
  t_point *curPoint;
  float dist;

  inc = malloc(sizeof(*inc));
  curPoint = getFirstPointVertical(t, rayAngle);
  inc->x = (isRightPart(rayAngle)) ? t->cubeSize : - t->cubeSize;
  inc->y = - inc->x * tan(degreesToRadians(rayAngle));
  while (insideMap(curPoint, t) && !isWall(curPoint, t))
  {
    free(curPoint);
    curPoint = getNextPointVertical(t, curPoint, inc);
  }
  free(inc);
  dist = getDist(curPoint, t);
  free(curPoint);
  return dist;
}

t_point *getFirstPointVertical(t_tool *t, float rayAngle)
{
  t_point *point;

  point = malloc(sizeof(*point));

  if (isRightPart(rayAngle))
    point->x = floor(t->pos->x / t->cubeSize) * t->cubeSize + t->cubeSize;
  else
    point->x = floor(t->pos->x / t->cubeSize) * t->cubeSize - E;
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
