/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:48:09 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/02 18:45:17 by hcherchi         ###   ########.fr       */
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
	float		x_move;
	float		y_move;
}				t_tool;

typedef struct	s_complex
{
	float			x;
	float			y;
}				t_complex;

void	light_pixel(t_tool *tools, float x, float y);

#endif
