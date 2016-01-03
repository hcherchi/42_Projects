/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:35:04 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/29 15:31:23 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		height(int *lim_upleft, char **tab_piece)
{
	int j;
	int i;
	int max;

	lim_upleft[0] = 4;
	max = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab_piece[j][i] == '#')
			{
				if (j < lim_upleft[0])
					lim_upleft[0] = j;
				if (j > max)
					max = j;
			}
			i++;
		}
		j++;
	}
	return (max - lim_upleft[0] + 1);
}

int		width(int *lim_upleft, char **tab_piece)
{
	int j;
	int i;
	int	max;

	max = 0;
	lim_upleft[1] = 4;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab_piece[j][i] == '#')
			{
				if (i < lim_upleft[1])
					lim_upleft[1] = i;
				if (i > max)
					max = i;
			}
			i++;
		}
		j++;
	}
	return (max - lim_upleft[1] + 1);
}

int		find_sqroot(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (find_sqroot(n + 1));
}

int		start_square(t_clean *struct_pieces, int nb)
{
	int	max;
	int	i;
	int n;

	i = 0;
	max = 0;
	n = find_sqroot(nb * 4);
	while (i < nb)
	{
		if (struct_pieces[i].w > max)
			max = struct_pieces[i].w;
		if (struct_pieces[i].h > max)
			max = struct_pieces[i].h;
		i++;
	}
	if (max > n)
		return (max);
	else
		return (n);
}
