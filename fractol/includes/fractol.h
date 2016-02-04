/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:48:09 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/04 12:08:32 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "mlx.h"
#include <math.h>
#include "libft.h"

typedef struct	s_tool
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		image_x;
	long double		image_y;
	int				i;
}				t_tool;

typedef struct	s_complex
{
	long double			x;
	long double			y;
}				t_complex;

void	pixel_put_to_image(unsigned long color, t_tool *tools, int x, int y);
void	light_pixel_mandelbrot(t_tool *tools, int x, int y);
void	init_param_mandelbrot(t_tool *tools);
void	run_through(t_tool *tools, void(light_pixel_fractal)(t_tool *, int, int));
int		key_press(int key, t_tool *tools);
int		mouse_hook(int button, int x, int y, t_tool *tools);
#endif
