/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:45:18 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/04 19:15:14 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_sol(char **sol, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		ft_putstr(sol[j]);
		ft_putchar('\n');
		j++;
	}
}

void	clean(char **sol, char c, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (sol[j][i] == c)
				sol[j][i] = '.';
			i++;
		}
		j++;
	}
}

char	**init_sol(int size)
{
	int		x;
	int		y;
	char	**sol;

	sol = (char **)malloc(sizeof(*sol) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		sol[y] = (char *)malloc(sizeof(*sol) * size + 1);
		while (x < size)
		{
			sol[y][x] = '.';
			x++;
		}
		sol[y][size] = '\0';
		y++;
	}
	return (sol);
}
