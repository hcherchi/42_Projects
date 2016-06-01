/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:37:05 by hcherchi          #+#    #+#             */
/*   Updated: 2016/06/01 10:37:07 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		change_to_sepia(t_color *color)
{
	color->r = (color->r * 0.393) + (color->g * 0.769) + (color->b * 0.189);
	color->g = (color->r * 0.349) + (color->g * 0.686) + (color->b * 0.168);
	color->b = (color->r * 0.272) + (color->g * 0.534) + (color->b * 0.131);
}

void		pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
	if (t->rt->sepia == 1)
		change_to_sepia(color);
	normalize_color(color);
	if (t->rt->screenshot == 0)
	{
		t->rt->image->data[x * t->rt->image->bpp / 8 +
		y * t->rt->image->size_line] = (unsigned char)color->b;
		t->rt->image->data[x * t->rt->image->bpp / 8 + 1 +
		y * t->rt->image->size_line] = (unsigned char)color->g;
		t->rt->image->data[x * t->rt->image->bpp / 8 + 2 +
		y * t->rt->image->size_line] = (unsigned char)color->r;
	}
	else
	{
		t->rt->image->screen[(x + y * t->rt->x_res) * 3 +
		0] = (unsigned char)color->r;
		t->rt->image->screen[(x + y * t->rt->x_res) * 3 +
		1] = (unsigned char)color->g;
		t->rt->image->screen[(x + y * t->rt->x_res) * 3 +
		2] = (unsigned char)color->b;
	}
}

void		draw(t_tool *t, int x, int y)
{
	t_ray	*ray;
	double	x0;
	double	y0;
	t_color	*moy_color;
	t_color	*color;

	moy_color = new_color();
	x0 = x;
	while (x0 <= x + 0.5)
	{
		y0 = y;
		while (y0 <= y + 0.5)
		{
			t->rt->depth = 0;
			ray = get_ray(t, x0, y0);
			color = get_color(ray, t);
			moy_color = add_color(moy_color, color);
			free(color);
			y0 += 0.5;
		}
		x0 += 0.5;
	}
	moy_color = div_color(moy_color, 4);
	pixel_put_to_image(t, x, y, moy_color);
	free(moy_color);
}
