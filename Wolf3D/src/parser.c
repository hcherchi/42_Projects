/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		checkDigit(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		checkGrid(t_tool *tools, char *filename)
{
	char	*line;
	int		ret;
	int		fd;
	char	**split;

	line = NULL;
	fd = open(filename, O_RDONLY);
	tools->nbcol = 0;
	tools->nbline = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tools->nbline += 1;
		split = ft_strsplit(line, ' ');
		if (tools->nbcol == 0)
			tools->nbcol = ft_tablen(split);
		else
		{
			if (tools->nbcol != ft_tablen(split))
				return (-1);
		}
		if (checkDigit(split) == -1)
			return (-1);
	}
	close(fd);
	return (ret);
}

void	printGrid(t_tool *t)
{
	int i;
	int j;

	i = 0;
	while (i < t->nbline)
	{
		j = 0;
		while (j < t->nbcol)
		{
			ft_putnbr(t->grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	readLine(int i, t_tool *t)
{
	char	*line;
	int		j;
	char	**split;

	line = NULL;
	j = 0;
	get_next_line(t->fd, &line);
	split = ft_strsplit(line, ' ');
	t->grid[i] = (int *)malloc(sizeof(int) * t->nbcol);
	while (j < t->nbcol)
	{
		t->grid[i][j] = ft_atoi(split[j]);
		j++;
	}
}

void readGrid(char *file, t_tool *t)
{
	int i;

	t->fd = open(file, O_RDONLY);

	t->grid = (int **)malloc(sizeof(int*) * t->nbline);
	i = 0;
	while (i < t->nbline)
	{
		readLine(i, t);
		i++;
	}
}
