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

void drawCol(int wallHeight, int col, t_tool *t)
{
  int min;
  int max;
  int line;

  line = 0;

  min = (t->screenHeight - wallHeight) / 2;
  max = min + wallHeight;
  while(line < t->screenHeight)
  {
    if (line <= min)
      pixel_put_to_image(SKY, t, col, line);
    else if (line > min && line < max)
      pixel_put_to_image(t->color, t, col, line);
    else
      pixel_put_to_image(GROUND, t, col, line);
    line++;
  }
}

int getWallColor(float wallDistHorizontal, float wallDistVertical, float dist, float ray)
{
  if (dist == wallDistHorizontal && isUpPart(ray))
    return NORTH;
  else if (dist == wallDistHorizontal && !isUpPart(ray))
    return SOUTH;
  else if (dist == wallDistVertical && isRightPart(ray))
    return EAST;
  else if (dist == wallDistVertical && !isRightPart(ray))
    return WEST;
  return 0;
}

int getWallHeight(int col, t_tool *t)
{
  float wallDistVertical;
  float wallDistHorizontal;
  float dist;
  float ray;
  float correctedDist;

  ray = adjustAngle(t->angle, (t->FOV / 2) - col * t->incAngle);
  wallDistHorizontal = getDist(getHorizontal(t, ray), t);
  wallDistVertical = getDist(getVertical(t, ray), t);
  dist = MIN(wallDistHorizontal, wallDistVertical);
  t->color = getWallColor(wallDistHorizontal, wallDistVertical, dist, ray);
  correctedDist = dist * cos(degreesToRadians(fabs(ray - t->angle)));
  return (t->cubeSize * t->dist) / correctedDist;
}

void launch(t_tool *t)
{
  int col;
  int wallHeight;
  col = 0;
  printf("Angle: %f\n", t->angle);
  t->mlx_img = mlx_new_image(t->mlx_ptr, t->screenWidth, t->screenHeight);
  while (col < t->screenWidth)
  {
    wallHeight = getWallHeight(col, t);
    drawCol(wallHeight, col, t);
    col++;
  }
  mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}
