/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/12/04 13:05:31 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_digit(char **split)
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

int		check_grid(t_tool *tools, int fd)
{
	char	*line;
	int		ret;
	char	**split;

	line = NULL;
	tools->nbcol = 0;
	tools->nbline = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tools->nbline += 1;
		split = ft_strsplit(line, ' ');
		free(line);
		if (tools->nbcol == 0)
			tools->nbcol = ft_tablen(split);
		else if (tools->nbcol != ft_tablen(split))
			return (-1);
		if (check_digit(split) == -1)
			return (-1);
		clean_tab(split);
	}
	close(fd);
	return (ret);
}

void	read_line(int i, t_tool *t, int fd)
{
	char	*line;
	int		j;
	char	**split;

	line = NULL;
	j = 0;
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	free(line);
	t->grid[i] = (int *)malloc(sizeof(int) * t->nbcol);
	while (j < t->nbcol)
	{
		t->grid[i][j] = ft_atoi(split[j]);
		j++;
	}
	clean_tab(split);
}

void	read_grid(t_tool *t, int fd)
{
	int i;

	t->grid = (int **)malloc(sizeof(int*) * t->nbline);
	i = 0;
	while (i < t->nbline)
	{
		read_line(i, t, fd);
		i++;
	}
	close(fd);
}
