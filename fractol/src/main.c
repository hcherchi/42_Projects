/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:56:45 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/05 13:10:16 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_through(t_tool *t, void (draw)(t_tool*, int, int))
{
	double x;
	double y;

	t->mlx_img = mlx_new_image(t->mlx_ptr, t->image_x, t->image_y);
	x = 0;
	while (x < t->image_x)
	{
		y = 0;
		while (y < t->image_y)
		{
			draw(t, x, y);
			y += 1;
		}
		x += 1;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}

void	error(void)
{
	ft_putendl("Invalid input, available fractals : julia, mandelbrot, lapin");
	exit(0);
}

void	launch_fractal(t_tool *tools)
{
	if (tools->type == 1)
		run_through(tools, light_pixel_julia);
	else if (tools->type == 2)
		run_through(tools, light_pixel_mandelbrot);
	else if (tools->type == 3)
		run_through(tools, light_pixel_lapin);
}

void	init_param(t_tool *tools, char *type)
{
	tools->type = 0;
	if (!ft_strcmp(type, "julia"))
		tools->type = 1;
	else if (!ft_strcmp(type, "mandelbrot"))
		tools->type = 2;
	else if (!ft_strcmp(type, "lapin"))
		tools->type = 3;
	else
		error();
	tools->image_x = 500;
	tools->image_y = 500;
	tools->i = 30;
	tools->x1 = -2;
	tools->x2 = -2 + 4 * tools->image_x / tools->image_y;
	tools->y1 = -2;
	tools->y2 = 2;
	tools->mouse_x = 0;
	tools->mouse_x = 0;
	tools->color = 0x990000;
}

int		main(int ac, char **av)
{
	t_tool	*t;

	t = malloc(sizeof(*t));
	if (ac != 2)
		error();
	init_param(t, av[1]);
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->image_x, t->image_y, "Fractol");
	launch_fractal(t);
	mlx_key_hook(t->mlx_win, key_press, t);
	mlx_mouse_hook(t->mlx_win, mouse_hook, t);
	if (t->type == 1)
		mlx_hook(t->mlx_win, 6, (1L << 6), mouse_pos, t);
	mlx_loop(t->mlx_ptr);
	return (0);
}
