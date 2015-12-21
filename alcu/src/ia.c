/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:08:47 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:10:43 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		iawin(t_line *lines, int i)
{
	while (i % 4 != 1)
		i--;
	if (lines->nb - i == 0)
	{
		if (lines->nb > 3)
			return (3);
		return (1);
	}
	return (lines->nb - i);
}

int		ialoose(t_line *lines, int i)
{
	while (i % 4 != 0)
		i--;
	if (lines->nb - i == 0)
	{
		if (lines->nb > 3)
			return (3);
		return (1);
	}
	return (lines->nb - i);
}

int		ia(t_line *lines)
{
	int i;

	i = lines->nb;
	if (!lines->next)
		return (iawin(lines, i));
	else if (lines->next->nb % 4 == 1)
		return (ialoose(lines, i));
	else
		return (iawin(lines, i));
}

void	playia(t_line *lines)
{
	int nb;
	int c;

	nb = al_count(lines);
	if (nb == 0)
		ft_putstr("LOOSER (y)\n");
	else
	{
		print_lines(&lines);
		ft_putstr("Henri's turn : ");
		c = ia(lines);
		remove_al(&lines, c);
		ft_putstr("He's taking off ");
		ft_putnbr(c);
		ft_putstr(" matches\n");
		player(lines);
	}
}
