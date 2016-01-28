/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:51:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/27 15:42:14 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			if (i + 1 < tools->nbline)
				draw_line(tools->points[i][j], tools->points[i + 1][j], tools);
			if (j + 1 < tools->nbcol)
				draw_line(tools->points[i][j], tools->points[i][j + 1], tools);
			j++;
		}
		i++;
	}
}

void	set_points(t_tool *tools)
{
	int i;
	int j;
	
	tools->points = malloc(sizeof(t_point *) * tools->nbline);
	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		tools->points[i] = malloc(sizeof(t_point) * tools->nbcol);
		while (j < tools->nbcol)
		{
			tools->points[i][j].z = tools->tab[i][j];
			tools->points[i][j].y = i * 50/1.4 + 200 - tools->points[i][j].z * 2;
			tools->points[i][j].x = j * 50 + 200;
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
			j++;
		}
		i++;
	}
	set_points(tools);
	print_grid(tools);
}
