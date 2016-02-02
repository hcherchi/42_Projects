/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:56:45 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/02 18:45:14 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

void	run_through(t_tool *tools)
{
	float x;
	float y;

	x = 0;
	while (x < 2560)
	{
		y = 0;
		while (y < 1400)
		{
			light_pixel(tools, x, y);
			y += 1;
		}
		x += 1;
	}
	ft_putendl("FINIIIIIIIIIIIIIII");
}

void	light_pixel(t_tool *tools, float x, float y)
{
	t_complex 	z;
	t_complex	c;
	t_complex	tmp;
	int i;
	int color;

	color = 0xCC0000;
	i = 0;
	c.x = (x - 2560 / 2 + tools->x_move) / 500;
	c.y = (y - 1400 / 2 + tools->y_move) / 500;
	z.x = 0.0;
	z.y = 0.0;

	while (((z.x * z.x) + (z.y * z.y)) < 4 && i < 50)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		i += 1;
	}
	if (i == 50)
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 0xCC0000);
	else
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, x, y, 0xCC0000 - (i * 1000));
}

int		key_press(int key, t_tool *tools)
{
	if (key == 126)
		tools->x_move -= 100;
	else if (key == 125)
		tools->x_move += 100;
	else if (key == 124)
		tools->y_move -= 100;
	else if (key == 123)
		tools->y_move += 100;
	mlx_clear_window(tools->mlx_ptr, tools->mlx_win);
	run_through(tools);
	return(0);
}

int		main(void)
{
	t_tool *tools;

	tools = malloc(sizeof(*tools));
	tools->x_move = 0;
	tools->y_move = 0;
	tools->mlx_ptr = mlx_init();
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, 2560, 1400, "I <3 Fractol");
	run_through(tools);
	mlx_key_hook(tools->mlx_win, key_press, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
