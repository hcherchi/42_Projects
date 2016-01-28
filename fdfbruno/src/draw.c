/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:39:30 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/27 17:32:25 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point a, t_point b, t_tool *tools)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
	int	z;

	i = 1;
	x = a.x;
	y = a.y;
	z = a.z;
	dx = b.x - a.x;
	dy = b.y - a.y;
	xinc = (dx > 0) ? 1 : -1 ;
	yinc = (dy > 0) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	if (z != 0)
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 0x00CC0000);
	else
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 808080);
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

			if (z != 0)
					mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 0x00CC0000);
			else
				mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 808080);
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
			if (z != 0)
				mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 0x00CC0000);
			else
				mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 808080);
			i++;
		}
	}
}
