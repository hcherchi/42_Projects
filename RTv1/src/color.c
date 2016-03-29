/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:59:53 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/29 16:06:45 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_color     *init_lumamb(t_tool *t, t_color *objcolor)
{
    t_color *base_color;
    
    base_color = malloc(sizeof(t_color));
    base_color->r = objcolor->r * t->lumamb;
    base_color->g = objcolor->g * t->lumamb;
    base_color->b = objcolor->b * t->lumamb;
    return (base_color);
}

void	normalize_color(t_color *final_color)
{
	if (final_color->r < 0)
		final_color->r = 0;
	if (final_color->b < 0)
		final_color->b = 0;
	if (final_color->g < 0)
		final_color->g = 0;
	if (final_color->r > 255)
		final_color->r = 255;
	if (final_color->b > 255)
		final_color->b = 255;
	if (final_color->g > 255)
		final_color->g = 255;
}

t_color	*add_color(t_color *color1, t_color *color2)
{
	t_color	*color;

	color = color1;
	color->r += color2->r;
	color->g += color2->g;
	color->b += color2->b;
	return (color);
}

t_color	*div_color(t_color *color, double n)
{
	t_color	*color2;
	
	color2 = color;
	color2->r /= n;
	color2->g /= n;
	color2->b /= n;
	return (color2);
}

t_color	*mult_color(t_color *color, double n)
{
	t_color	*color2;

	color2 = color;
	color2->r *= n;
	color2->g *= n;
	color2->b *= n;
	return (color2);
}

t_colors    *new_colors(void)
{
    t_colors *colors;
    
    colors = malloc(sizeof(t_colors));
    colors->refract = NULL;
    colors->reflect = NULL;
    colors->base = NULL;
    return (colors);
}

t_color	*new_color(void)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
