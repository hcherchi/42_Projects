/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:43:37 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/04 18:16:42 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	light_pixel_lapin(t_tool *t, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;

	z.x = (double)x / ((double)t->image_x / (t->x2 - t->x1)) + t->x1;
	z.y = (double)y / ((double)t->image_y / (t->y2 - t->y1)) + t->y1;
	c.x = -0.12;
	c.y = 0.75;
	i = 0;
	while ((z.x * z.x) + (z.y * z.y) < 2.1015 && i < t->i)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i += 1;
	}
	if (i == t->i)
		pixel_put_to_image(t->color, t, x, y);
	else
		pixel_put_to_image(t->color + (10000 * i), t, x, y);
}

void	light_pixel_mandelbrot(t_tool *t, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;

	i = 0;
	c.x = (double)x / ((double)t->image_x / (t->x2 - t->x1)) + t->x1;
	c.y = (double)y / ((double)t->image_y / (t->y2 - t->y1)) + t->y1;
	z.x = 0.0;
	z.y = 0.0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && i < t->i)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i += 1;
	}
	if (i == t->i)
		pixel_put_to_image(t->color, t, x, y);
	else
		pixel_put_to_image(t->color + (10000 * i), t, x, y);
}

void	light_pixel_julia(t_tool *t, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;

	i = 0;
	z.x = (double)x / ((double)t->image_x / (t->x2 - t->x1)) + t->x1;
	z.y = (double)y / ((double)t->image_y / (t->y2 - t->y1)) + t->y1;
	c.x = t->mouse_x;
	c.y = t->mouse_y;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && i < t->i)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i += 1;
	}
	if (i == t->i)
		pixel_put_to_image(t->color, t, x, y);
	else
		pixel_put_to_image(t->color + (10000 * i), t, x, y);
}
