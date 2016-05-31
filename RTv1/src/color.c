/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:21:45 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 19:33:19 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_color		*add_color(t_color *color1, t_color *color2)
{
	t_color	*color;

	color = new_color();
	color->r = color1->r + color2->r;
	color->g = color1->g + color2->g;
	color->b = color1->b + color2->b;
	return (color);
}

t_color		*div_color(t_color *color, double n)
{
	t_color	*color1;

	color1 = new_color();
	color1->r = color->r / n;
	color1->g = color->g / n;
	color1->b = color->b / n;
	return (color1);
}

t_color		*mult_color(t_color *color, double n)
{
	t_color	*color1;

	color1 = new_color();
	color1->r = color->r * n;
	color1->g = color->g * n;
	color1->b = color->b * n;
	return (color1);
}

t_colors	*new_colors(void)
{
	t_colors *colors;

	colors = malloc(sizeof(t_colors));
	colors->refract = NULL;
	colors->reflect = NULL;
	colors->base = NULL;
	return (colors);
}

t_color		*new_color(void)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
