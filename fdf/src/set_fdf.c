/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:51:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/27 20:59:06 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"	

void	rotate_point(t_point *a, int cx, int cy, float angle)
{
	float s;
	float c;
	float newx;
	float newy;

	s = sin(angle);
	c = cos(angle);
	a->x -= cx;
	a->y -= cy;
	newx = a->x  * c - a->y * s;
	newy = a->x * s + a->y * c;
	a->x = newx + cx;
	a->y = newy + cy;
}



t_point	*create_point(t_tool *tools,int i, int j)
{
	float k;
	t_point *point;

	point = malloc(sizeof(t_point *));
	k = (float)(tools->wwin)/ (float)tools->nbcol;
	point->x = j * k;
	point->y = i * k;
	rotate_point(point, 0, 0, 0.2);
	point->y /= 1.4;
	if (tools->wmax && tools->wmin && tools->hmin && tools->hmax)
	{
		point->y += 1400/2 - tools->hmax->y + (tools->hmax->y - tools->hmin->y)/2;
		point->x += 2560/2 - tools->wmax->x + (tools->wmax->x - tools->wmin->x)/2;
	}
	point->z = tools->tab[i][j];
	point->y -= tools->tab[i][j] / 5;
	return (point);
}

void	print_grid(t_tool *tools)
{
	int i;
	int j;

	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		while (j < tools->nbcol)
		{
			if (j + 1 < tools->nbcol)
				draw_line(tools->points[i][j], tools->points[i][j + 1], tools);
			if (i + 1 < tools->nbline)
				draw_line(tools->points[i][j], tools->points[i + 1][j], tools);
			j++;
		}
		i++;
	}
}

void	find_min_max(t_tool *tools)
{
	tools->wmax = NULL;
	tools->wmin = NULL;
	tools->hmin = NULL;
	tools->hmax = NULL;
	tools->wmax = create_point(tools, 0, tools->nbcol - 1);
	tools->wmin = create_point(tools, tools->nbline - 1, 0);
	tools->hmin = create_point(tools, tools->nbline - 1, tools->nbcol - 1);
	tools->hmax = create_point(tools, 0, 0);
}

void	set_points(t_tool *tools)
{
	int i;
	int j;
	
	find_min_max(tools);
	tools->points = malloc(sizeof(t_point**) * tools->nbline);
	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		tools->points[i] = malloc(sizeof(t_point*) * tools->nbcol);
		while (j < tools->nbcol)
		{
			tools->points[i][j] = create_point(tools, i, j);
			j++;
		}
		i++;
	}
}

void	launch_fdf(t_tool *tools)
{
	int 	i;
	int 	j;
	char *line;
	char **split;

	tools->zmin = 0;
	tools->zmax = 0;
	tools->tab = (int **)malloc(sizeof(int*) * tools->nbline);
	line = NULL;
	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		get_next_line(tools->fd, &line);
		split = ft_strsplit(line, ' ');
		tools->tab[i] = (int *)malloc(sizeof(int) * tools->nbcol);
		while (j < tools->nbcol)
		{
			tools->tab[i][j] = ft_atoi(split[j]);
			if (tools->tab[i][j] < tools->zmin)
				tools->zmin = tools->tab[i][j];
			if (tools->tab[i][j] > tools->zmax)
				tools->zmax = tools->tab[i][j];
			j++;
		}
		i++;
	}
	set_points(tools);
	print_grid(tools);
}
