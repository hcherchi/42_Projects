/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:47:44 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:36:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		launch(int ac, char **av)
{
	char	*buf;
	t_line	*lines;

	buf = NULL;
	if (ac == 1)
		buf = standard_input();
	else if (ac == 2)
		buf = read_file(get_ssize_file(av[1]), av[1]);
	else
		ft_putstr_fd("Too much arguments\n", 2);
	if (!valid_file(buf))
		return (0);
	else
	{
		if (!(lines = init_lines(buf)))
			return (0);
		reverse(&lines);
		player(lines);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ft_menu())
	{
		launch(ac, av);
	}
	return (0);
}
