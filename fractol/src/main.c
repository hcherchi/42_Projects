/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:56:45 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/04 12:06:43 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_through(t_tool *tools, void(light_pixel_fractal)(t_tool*, int, int))
{
	long double x;
	long double y;

	tools->mlx_img = mlx_new_image(tools->mlx_ptr, tools->image_x, tools->image_y);
	x = 0;
	while (x < tools->image_x)
	{
		y = 0;
		while (y < tools->image_y)
		{
			light_pixel_fractal(tools, x, y);
			y += 1;
		}
		x += 1;
	}
	mlx_put_image_to_window(tools->mlx_ptr, tools->mlx_win, tools->mlx_img, 0, 0);
}

int		main(void)
{
	t_tool *tools;

	tools = malloc(sizeof(*tools));
	init_param_mandelbrot(tools);
	tools->mlx_ptr = mlx_init();
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, tools->image_x + 1, tools->image_y + 1, "I <3 Fractol");
	run_through(tools, light_pixel_mandelbrot);
	mlx_key_hook(tools->mlx_win, key_press, tools);
	mlx_mouse_hook(tools->mlx_win, mouse_hook , tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
