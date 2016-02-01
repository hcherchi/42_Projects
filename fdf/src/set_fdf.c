/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:51:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/31 20:42:48 by hcherchi         ###   ########.fr       */
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

void	launch_fdf(t_tool *tools)
{
	int	i;

	tools->zmin = 0;
	tools->zmax = 0;
	tools->tab = (int **)malloc(sizeof(int*) * tools->nbline);
	i = 0;
	while (i < tools->nbline)
	{
		convert_line(i, tools);
		i++;
	}
	set_points(tools);
	print_grid(tools);
}

void	convert_line(int i, t_tool *tools)
{
	char	*line;
	int		j;
	char	**split;

	line = NULL;
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
}
