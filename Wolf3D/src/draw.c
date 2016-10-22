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
    if (line > min && line < max)
    {
      pixel_put_to_image(0x990000, t, col, line);
    }
    line++;
  }
}

int getWallHeight(int col, t_tool *t)
{
  int wallHeight;
  float wallDistVertical;
  float wallDistHorizontal;
  float dist;
  float ray;


  ray = t->angle + (t->FOV / 2) - col * t->incAngle;
  printf("rayAngle: %f\n", ray);
  wallDistHorizontal = getDist(getHorizontal(t, ray), t);
  wallDistVertical = getDist(getVertical(t, ray), t);
  printf("Vertical distance: %f\nHorizontal distance: %f\n", wallDistVertical, wallDistHorizontal);
  dist = MIN(wallDistHorizontal, wallDistVertical);
  if(dist == -1)
  {
    return 0;
  }
  wallHeight = (t->cubeSize * t->dist) / dist;

  return wallHeight;
}

void launch(t_tool *t)
{
  int col;
  int wallHeight;
  col = 0;

  t->mlx_img = mlx_new_image(t->mlx_ptr, t->screenWidth, t->screenHeight);
  while (col < t->screenWidth)
  {
    ft_putstr("running column ");
    ft_putnbr(col);
    ft_putchar('\n');
    wallHeight = getWallHeight(col, t);
    drawCol(wallHeight, col, t);
    col++;
  }
  mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}
