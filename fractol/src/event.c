/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:03:03 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/05 13:11:51 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int key, t_tool *tools)
{
	if (key == 53)
		exit(0);
	else if (key == 78)
		tools->i -= 50;
	else if (key == 69)
		tools->i += 50;
	mlx_destroy_image(tools->mlx_ptr, tools->mlx_img);
	launch_fractal(tools);
	return (0);
}

int		mouse_pos(int x, int y, t_tool *tools)
{
	tools->mouse_x = x / (tools->image_x / (tools->x2 - tools->x1)) + tools->x1;
	tools->mouse_y = y / (tools->image_y / (tools->y2 - tools->y1)) + tools->y1;
	tools->color += 1000;
	mlx_destroy_image(tools->mlx_ptr, tools->mlx_img);
	run_through(tools, light_pixel_julia);
	return (0);
}

void	zoom_in(t_tool *tools, double xspan, double yspan, t_complex new)
{
	double tmp;

	tmp = tools->x1;
	tools->x1 = (new.x + (tools->x2 + tools->x1) / 2) / 2 - (xspan * 0.4);
	tools->x2 = (new.x + (tools->x2 + tmp) / 2) / 2 + (xspan * 0.4);
	tmp = tools->y1;
	tools->y1 = (new.y + (tools->y2 + tools->y1) / 2) / 2 - (yspan * 0.4);
	tools->y2 = (new.y + (tools->y2 + tmp) / 2) / 2 + (yspan * 0.4);
}

void	zoom_out(t_tool *tools, double xspan, double yspan)
{
	tools->x1 = tools->x1 - (xspan * 0.52);
	tools->x2 = tools->x2 + (xspan * 0.52);
	tools->y1 = tools->y1 - (yspan * 0.52);
	tools->y2 = tools->y2 + (yspan * 0.52);
}

int		mouse_hook(int button, int x, int y, t_tool *tools)
{
	t_complex	new;
	double		xspan;
	double		yspan;

	xspan = tools->x2 - tools->x1;
	yspan = tools->y2 - tools->y1;
	new.x = x / (tools->image_x / (tools->x2 - tools->x1)) + tools->x1;
	new.y = y / (tools->image_y / (tools->y2 - tools->y1)) + tools->y1;
	if (button == 5)
		zoom_in(tools, xspan, yspan, new);
	else if (button == 4)
		zoom_out(tools, xspan, yspan);
	mlx_destroy_image(tools->mlx_ptr, tools->mlx_img);
	launch_fractal(tools);
	return (0);
}
