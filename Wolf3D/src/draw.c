/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/12/04 13:11:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	launch(t_tool *t)
{
	int col;
	int wall_height;

	col = 0;
	t->mlx_img = mlx_new_image(t->mlx_ptr, t->width, t->height);
	while (col < t->width)
	{
		wall_height = get_wall_height(col, t);
		draw_col(wall_height, col, t);
		col++;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}

void	draw_col(int wall_height, int col, t_tool *t)
{
	int min;
	int max;
	int line;

	line = 0;
	min = (t->height - wall_height) / 2;
	max = min + wall_height;
	while (line < t->height)
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

int		get_wall_height(int col, t_tool *t)
{
	float	vertical_dist;
	float	horizontal_dist;
	float	dist;
	float	ray;
	float	corrected_dist;

	ray = adjust_angle(t->angle, (t->fov / 2) - col * t->inc_angle);
	horizontal_dist = get_horizontal_dist(t, ray);
	vertical_dist = get_vertical_dist(t, ray);
	dist = MIN(horizontal_dist, vertical_dist);
	t->color = get_wall_color(horizontal_dist, vertical_dist, dist, ray);
	corrected_dist = dist * cos(D_TO_R(fabs(ray - t->angle)));
	return (t->cube * t->dist) / corrected_dist;
}

int		get_wall_color(float horizontal, float vertical, float dist, float ray)
{
	if (dist == horizontal && is_up_part(ray))
		return (NORTH);
	else if (dist == horizontal && !is_up_part(ray))
		return (SOUTH);
	else if (dist == vertical && is_right_part(ray))
		return (EAST);
	else if (dist == vertical && !is_right_part(ray))
		return (WEST);
	return (0);
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
