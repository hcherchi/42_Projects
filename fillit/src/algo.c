/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:06:00 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/29 15:30:20 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ok_toput(char **sol, t_clean cut_piece)
{
	int	j;
	int	i;

	j = 0;
	while (j < cut_piece.h)
	{
		i = 0;
		while (i < cut_piece.w)
		{
			if (sol[cut_piece.y + j][cut_piece.x + i] != '.' &&
				cut_piece.tab_piece[j][i] == '#')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	put_piece(char **sol, t_clean cut_piece)
{
	int	i;
	int	j;

	j = 0;
	while (j < cut_piece.h)
	{
		i = 0;
		while (i < cut_piece.w)
		{
			if (cut_piece.tab_piece[j][i] == '#')
				sol[cut_piece.y + j][cut_piece.x + i] = cut_piece.let;
			i++;
		}
		j++;
	}
}

int		avance(t_clean *struct_pieces, int size, int i, char **sol)
{
	if (struct_pieces[i].x == size - struct_pieces[i].w &&
		struct_pieces[i].y == size - struct_pieces[i].h)
	{
		struct_pieces[i].x = 0;
		struct_pieces[i].y = 0;
		if (i == 0)
			return (-1);
		i--;
		clean(sol, struct_pieces[i].let, size);
		return (avance(struct_pieces, size, i, sol));
	}
	else if (struct_pieces[i].x < size - struct_pieces[i].w)
		struct_pieces[i].x++;
	else
	{
		struct_pieces[i].y++;
		struct_pieces[i].x = 0;
	}
	return (i);
}

void	resol(char **sol, t_clean *struct_pieces, int nb, int size)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (i == -1)
		{
			free(sol);
			sol = init_sol(size + 1);
			resol(sol, struct_pieces, nb, size + 1);
			return ;
		}
		if (ok_toput(sol, struct_pieces[i]) == 0)
		{
			put_piece(sol, struct_pieces[i]);
			i++;
		}
		else
			i = avance(struct_pieces, size, i, sol);
	}
	ft_print_sol(sol, size);
}
