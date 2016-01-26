/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:51:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/26 12:24:49 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	

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
			ft_putnbr(tools->tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	set_points(t_tool *tools)
{
	int i;
	int j;
	
	i = 0;
	while (i < tools->nbline)
	{
		j = 0;
		while (j < tools->nbcol)
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
	print_grid(tools);
	set_points(tools);
}
