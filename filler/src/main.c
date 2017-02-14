/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/05 15:06:20 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char **fill_grid(int height)
{
	int i;
	char *line;
	char **grid;
	char **split;

	grid = malloc(sizeof(char *) * (height + 1));
	line = NULL;
	i = 0;
	while (i < height)
	{
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		grid[i] = split[1];
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

char **fill_piece(int height)
{
	int i;
	char *line;
	char **piece;

	piece = malloc(sizeof(char *) * (height + 1));
	line = NULL;
	i = 0;
	while (i < height)
	{
		get_next_line(0, &line);
		piece[i] = line;
		i++;
	}
	piece[i] = NULL;
	return (piece);
}


t_tools *fill_tools()
{
	char **split;
	t_tools *tools;
	char *line;

	tools = malloc(sizeof(t_tools *));

	get_next_line(0, &line);

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	get_next_line(0, &line);

	tools->grid = fill_grid(ft_atoi(split[1]));

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	tools->piece = fill_piece(ft_atoi(split[1]));

	return tools;
}

int		main(void)
{
	t_tools *tools;

	tools = fill_tools();
	ft_putendl("0 0");
	return (0);
}
