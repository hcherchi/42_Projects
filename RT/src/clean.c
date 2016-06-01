/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:21:34 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 22:48:31 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	clean_tools(t_tool **tools)
{
	if ((*tools)->m)
		clean_menu(&(*tools)->m);
	if ((*tools)->rt)
		clean_rt(&(*tools)->rt);
	if ((*tools)->mlx_ptr)
	{
		free((*tools)->mlx_ptr);
		(*tools)->mlx_ptr = NULL;
	}
	if (*tools)
	{
		free(*tools);
		*tools = NULL;
	}
}

void	clean_menu(t_menu **m)
{
	if ((*m)->mlx_win)
	{
		free((*m)->mlx_win);
		(*m)->mlx_win = NULL;
	}
	if ((*m)->bg)
		clean_image(&(*m)->bg);
	if (*m)
	{
		free(*m);
		*m = NULL;
	}
}

void	clean_ray(t_ray **ray)
{
	if ((*ray)->o)
	{
		free((*ray)->o);
		(*ray)->o = NULL;
	}
	if ((*ray)->d)
	{
		free((*ray)->d);
		(*ray)->d = NULL;
	}
	if (*ray)
	{
		free(*ray);
		*ray = NULL;
	}
}

void	clean_rt(t_rt **rt)
{
	if ((*rt)->sky)
		clean_image(&(*rt)->sky);
	if ((*rt)->image)
		clean_image(&(*rt)->image);
	if ((*rt)->l_objects)
		clean_obj(&(*rt)->l_objects);
	if ((*rt)->l_lights)
		clean_lights(&(*rt)->l_lights);
	if ((*rt)->up)
		clean_cams(&(*rt)->up, 4);
	if ((*rt)->mid)
		clean_cams(&(*rt)->mid, 5);
	*rt = NULL;
}

void	clean_image(t_image **image)
{
	if ((*image)->data)
	{
		free((*image)->data);
		(*image)->data = NULL;
	}
	if ((*image)->mlx_img)
	{
		free((*image)->mlx_img);
		(*image)->mlx_img = NULL;
	}
	if ((*image)->texture)
	{
		free((*image)->texture);
		(*image)->texture = NULL;
	}
	if ((*image)->screen)
	{
		free((*image)->screen);
		(*image)->screen = NULL;
	}
	if (*image)
	{
		free(*image);
		*image = NULL;
	}
}
