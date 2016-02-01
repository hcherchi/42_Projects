/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:39:30 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:04:36 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point *a, t_point *b, t_tool *tools)
{
	int		color;
	t_math	*m;

	m = malloc(sizeof(*m));
	color = choose_color(tools, a, b);
	m->x = a->x;
	m->y = a->y;
	m->dx = b->x - a->x;
	m->dy = b->y - a->y;
	m->xinc = (m->dx > 0) ? 1 : -1;
	m->yinc = (m->dy > 0) ? 1 : -1;
	m->dx = abs(m->dx);
	m->dy = abs(m->dy);
	mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, m->x, m->y, color);
	if (m->dx > m->dy)
		horizontal_case(m, tools, color);
	else
		vertical_case(m, tools, color);
}

int		choose_color(t_tool *tools, t_point *a, t_point *b)
{
	int	range;
	int	z;

	range = tools->zmax - tools->zmin;
	z = (a->z >= b->z) ? b->z : a->z;
	if (z < -10)
		return (0x00003399);
	else if (z < -5)
		return (0x000066FF);
	else if (z <= 0)
		return (0x000099FF);
	else if (z < 2 * tools->zmax / 18)
		return (0x66CC33);
	else if (z < 4 * tools->zmax / 18)
		return (0x009933);
	else if (z < 6 * tools->zmax / 18)
		return (0x006600);
	else if (z < 10 * tools->zmax / 18)
		return (0x996633);
	else if (z < 14 * tools->zmax / 18)
		return (0x993300);
	else
		return (0x00FFFFFF);
}

void	horizontal_case(t_math *m, t_tool *tools, int color)
{
	int i;

	i = 1;
	m->cumul = m->dx / 2;
	while (i <= m->dx)
	{
		m->x += m->xinc;
		m->cumul += m->dy;
		if (m->cumul >= m->dx)
		{
			m->cumul -= m->dx;
			m->y += m->yinc;
		}
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, m->x, m->y, color);
		i++;
	}
}

void	vertical_case(t_math *m, t_tool *tools, int color)
{
	int i;

	i = 0;
	m->cumul = m->dy / 2;
	while (i <= m->dy)
	{
		m->y += m->yinc;
		m->cumul += m->dx;
		if (m->cumul >= m->dy)
		{
			m->cumul -= m->dy;
			m->x += m->xinc;
		}
		mlx_pixel_put(tools->mlx_ptr, tools->mlx_win, m->x, m->y, color);
		i++;
	}
}
