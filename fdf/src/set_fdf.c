/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:51:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/25 18:05:18 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	launch(t_tool *tools, char *filename)
{
	int		fd;
	int		tab[tools->nbline][tools->nbcol];
	int 	i;
	int 	j;
	char *line;
	char **split;

	line = NULL;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < tools->nbline)
	{
		j = 0;
		get_next_line(fd, &line);
		while (j < tools->nbcol)
		{
			split = ft_strsplit(line, ' ');
			tab[i][j] =;
			i++;
		}
	}
}
