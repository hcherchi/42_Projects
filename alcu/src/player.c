/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:10:43 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:19:12 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	player(t_line *lines)
{
	int nb;

	nb = al_count(lines);
	if (nb == 0)
		ft_putstr("You win the game. But we know you know the trick..\n");
	else
	{
		print_lines(&lines);
		ft_putstr("Player's turn : ");
		remove_al(&lines, ask_nb(lines));
		playia(lines);
	}
}

int		ask_nb(t_line *lines)
{
	char	*buf;
	int		max;

	max = 3;
	if (lines->nb < 3)
		max = lines->nb;
	if (!(buf = (char *)malloc(sizeof(*buf) * (BUF_SIZE + 1))))
		return (-1);
	ft_putstr("How many matches would you like to take off ?: ");
	while ((read(0, buf, BUF_SIZE)) > 0)
	{
		if (max > lines->nb)
		{
			ft_putendl_fd("Not enough matchs in last rows", 2);
			player(lines);
		}
		if (buf[0] <= max + '0' && buf[0] > '0' && buf[1] == '\n')
			return (buf[0] - '0');
		else
		{
			ft_putstr("Choose a number between 1 and ");
			ft_putnbr(max);
		}
	}
	return (0);
}
