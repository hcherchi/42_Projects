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

int   isWall(t_point *intersection, t_tool *t)
{
  int i;
  int j;

  i = intersection->x / t->cubeSize;
  j = intersection->y / t->cubeSize;
  if (t->grid[i][j] == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int   insideMap(t_point *intersection, t_tool *t)
{
  int i;
  int j;

  i = intersection->x / t->cubeSize;
  j = intersection->y / t->cubeSize;
  if (i < t->nbline && j < t->nbcol)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

float getDist(t_point *wall, t_tool *t)
{
  if (!wall)
  {
    return -1;
  }
  return (sqrt(pow(t->pos->x - wall->x, 2) + pow(t->pos->y - wall->y, 2)));
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
