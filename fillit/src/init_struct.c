/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:21:54 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/04 20:05:30 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**split_piece(char *piece)
{
	char	**tab_piece;
	int		i;
	int		c;

	c = 0;
	i = 0;
	tab_piece = (char **)malloc(sizeof(*tab_piece) * 4);
	while (piece[i] != '\0')
	{
		tab_piece[c] = ft_strsub(piece, i, 4);
		c++;
		i += 5;
	}
	return (tab_piece);
}

char	***split_pieces(char *pieces)
{
	char	***tab_pieces;
	int		i;
	int		c;
	int		len;

	c = 0;
	i = 0;
	len = nb_pieces(pieces);
	tab_pieces = (char ***)malloc(sizeof(*tab_pieces) * len);
	while (len > 0)
	{
		tab_pieces[c] = split_piece(ft_strsub(pieces, i, 20));
		c++;
		len--;
		i += 21;
	}
	return (tab_pieces);
}

t_clean	cut_piece(char **piece)
{
	char	**tab_cut;
	t_clean	cut;
	int		j;
	int		*lim_upleft;

	j = 0;
	lim_upleft = (int *)malloc(sizeof(*lim_upleft) * 2);
	cut.w = width(lim_upleft, piece);
	cut.h = height(lim_upleft, piece);
	cut.x = 0;
	cut.y = 0;
	tab_cut = (char **)malloc(sizeof(*tab_cut) * cut.h);
	while (j < cut.h)
	{
		tab_cut[j] = ft_strsub(piece[lim_upleft[0] + j], lim_upleft[1], cut.w);
		j++;
	}
	cut.tab_piece = tab_cut;
	j = 0;
	free(lim_upleft);
	return (cut);
}

t_clean	*init_struct(char *pieces, int nb)
{
	char	***tab_pieces;
	int		i;
	t_clean	*cut_pieces;

	i = 0;
	tab_pieces = split_pieces(pieces);
	cut_pieces = (t_clean *)malloc(sizeof(t_clean) * nb);
	while (i < nb)
	{
		cut_pieces[i] = cut_piece(tab_pieces[i]);
		free(tab_pieces[i]);
		cut_pieces[i].let = i + 65;
		i++;
	}
	free(tab_pieces);
	return (cut_pieces);
}

int		nb_pieces(char *pieces)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (pieces[i] != '\0')
	{
		if (pieces[i] == '\n' && pieces[i + 1] == '\n')
			nb++;
		i++;
	}
	nb++;
	return (nb);
}
