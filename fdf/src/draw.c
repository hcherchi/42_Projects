/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:39:30 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/28 17:26:54 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point *a, t_point *b, t_tool *tools)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
	int color;
	int	range;
	int z;
	
	range = tools->zmax - tools->zmin;
 	z = (a->z >= b->z) ? b->z : a->z;
	if (z < -10)
		color = 0x00003399;
	else if (z < -5)
		color = 0x000066FF;
	else if (z <= 0)
		color = 0x000099FF;
	else if (z < (range + tools->zmin) / 10)
		color = 0x0033CC00;
	else if (z < 2 * (range + tools->zmin)/ 10)
		color = 0x00009900;
	else if (z < 3 * (range + tools->zmin)/ 10)
		color = 0x00006600;
	else if (z < 4 * (range + tools->zmin)/ 10)
		color = 0x00666600;
	else if (z < 5 * (range + tools->zmin) / 10)
		color = 0x00996600;
	else if (z < 6 * (range + tools->zmin) / 10)
		color = 0x00663300;
	else if (z < 7 * (range + tools->zmin) / 10)
		color = 0x00660000;
	else if (z < 8 * (range + tools->zmin) / 10)
		color = 0x00999999;
	else if (z < 9 * (range + tools->zmin) / 10)
		color = 0x00CCCCCC;
	else
		color = 0x00FFFFFF;
	i = 1;
	x = a->x;
	y = a->y;
	dx = b->x - a->x;
	dy = b->y - a->y;
	xinc = (dx > 0) ? 1 : -1 ;
	yinc = (dy > 0) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, color);
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y,color);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, color);
			i++;
		}
	}
}
