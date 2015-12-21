/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:09:40 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:23:49 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_menu(void)
{
	char *buf;

	buf = (char *)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (!buf)
		return (1);
	ft_putstr("Welcome to the new game alum1, ");
	ft_putendl("are you ready to fight the only competition bot");
	ft_putendl("... Henry !");
	ft_putendl("The strongest bot ever seen");
	ft_putstr("If you want to try the experience ");
	ft_putendl("and put your nerves a rough ordeal");
	ft_putendl("So prepare yourself mentally, and dare to start the game !\n");
	ft_putstr("start the game? (y or n) : ");
	while ((read(0, buf, BUF_SIZE)) > 0)
	{
		if (buf[0] == 'y')
			return (1);
		else if (buf[0] == 'n')
			return (0);
		else
			ft_putstr("Please enter y for yes, or n for not\n");
	}
	return (0);
}
