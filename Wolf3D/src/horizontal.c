/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point *getHorizontal(t_tool *t, float rayAngle)
{
  t_point *inc;
  t_point *curPoint;
  int inside;

  inc = malloc(sizeof(*inc));
  curPoint = getFirstPointHorizontal(t, rayAngle);

  inc->x = t->cubeSize / tan(degreesToRadians(rayAngle));
  inc->y = (rayAngle > 0) ? t->cubeSize : - t->cubeSize;
  while ((inside = insideMap(curPoint, t)) && !isWall(curPoint, t))
  {
    curPoint = getNextPointHorizontal(t, curPoint, inc);
    printf("Horizontal search\nX: %d\nY: %d\n", (int)(curPoint->x / t->cubeSize), (int)(curPoint->y / t->cubeSize));
  }
  if (!inside)
  {
    return NULL;
  }
  return curPoint;
}

t_point *getFirstPointHorizontal(t_tool *t, float rayAngle)
{
  t_point *point;

  point = malloc(sizeof(*point));

  if (rayAngle > 0)
  {
    point->y = floor(t->pos->y / t->cubeSize) * t->cubeSize - 1;
  }
  else
  {
    point->y = floor(t->pos->y / t->cubeSize) * t->cubeSize + t->cubeSize;
  }
  point->x = t->pos->x + fabs(t->pos->y - point->y) / tan(degreesToRadians(rayAngle));
  return point;
}

t_point *getNextPointHorizontal(t_tool *t, t_point *curPoint, t_point *inc)
{
  t_point *nextPoint;
  float dist;

  nextPoint = malloc(sizeof(*nextPoint));
  nextPoint->x = curPoint->x + inc->x;
  nextPoint->y = curPoint->y + inc->y;
  dist = getDist(nextPoint, t);
  return nextPoint;
}
