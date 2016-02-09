/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:48:09 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/04 18:15:36 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include "libft.h"

typedef struct	s_tool
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			image_x;
	int			image_y;
	double		mouse_x;
	double		mouse_y;
	int			i;
	int			color;
	int			type;
	int			bpp;
	int			endian;
	int			size_line;
}				t_tool;

typedef struct	s_complex
{
	double		x;
	double		y;
}				t_complex;

void			launch_fractal(t_tool *tools);
void			error(void);
int				mouse_pos(int x, int y, t_tool *tools);
void			pixel_put_to_image(int c, t_tool *t, int x, int y);
void			light_pixel_mandelbrot(t_tool *tools, int x, int y);
void			light_pixel_julia(t_tool *tools, int x, int y);
void			light_pixel_lapin(t_tool *tools, int x, int y);
void			init_param(t_tool *tools, char *type);
void			run_through(t_tool *tools, void(draw)(t_tool *, int, int));
int				key_press(int key, t_tool *tools);
int				mouse_hook(int button, int x, int y, t_tool *tools);
void			zoom_in(t_tool *tools, double xsp, double ysp, t_complex new);
void			zoom_out(t_tool *tools, double xspan, double yspan);
#endif
