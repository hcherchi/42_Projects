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

void launch(t_tool *t)
{
  int col;
  int wallHeight;
  col = 0;
  t->mlx_img = mlx_new_image(t->mlx_ptr, t->screenWidth, t->screenHeight);
  while (col < t->screenWidth)
  {
    wallHeight = getWallHeight(col, t);
    drawCol(wallHeight, col, t);
    col++;
  }
  mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}

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

int getWallHeight(int col, t_tool *t)
{
  float verticalDist;
  float horizontalDist;
  float dist;
  float ray;
  float correctedDist;

  ray = adjustAngle(t->angle, (t->FOV / 2) - col * t->incAngle);
  horizontalDist = getHorizontalDist(t, ray);
  verticalDist = getVerticalDist(t, ray);
  dist = MIN(horizontalDist, verticalDist);
  t->color = getWallColor(horizontalDist, verticalDist, dist, ray);
  correctedDist = dist * cos(degreesToRadians(fabs(ray - t->angle)));
  return (t->cubeSize * t->dist) / correctedDist;
}

int getWallColor(float horizontalDist, float verticalDist, float dist, float ray)
{
  if (dist == horizontalDist && isUpPart(ray))
    return NORTH;
  else if (dist == horizontalDist && !isUpPart(ray))
    return SOUTH;
  else if (dist == verticalDist && isRightPart(ray))
    return EAST;
  else if (dist == verticalDist && !isRightPart(ray))
    return WEST;
  return 0;
}

void	pixel_put_to_image(int color, t_tool *t, int x, int y)
{
	char			*data;
	unsigned long	lcolor;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	lcolor = mlx_get_color_value(t->mlx_ptr, color);
	data = mlx_get_data_addr(t->mlx_img, &t->bpp, &t->size_line, &t->endian);
	r = ((lcolor & 0xFF0000) >> 16);
	g = ((lcolor & 0xFF00) >> 8);
	b = ((lcolor & 0xFF));
	data[x * t->bpp / 8 + y * t->size_line] = b;
	data[x * t->bpp / 8 + 1 + y * t->size_line] = g;
	data[x * t->bpp / 8 + 2 + y * t->size_line] = r;
}
