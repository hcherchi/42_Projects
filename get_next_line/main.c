/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:58:45 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/19 15:29:21 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_putendl("error");
		while (get_next_line(fd, &line) == 1)
			ft_putendl(line);
	}
	else if (argc == 1)
	{
		while (get_next_line(0, &line) == 1)
			ft_putendl(line);
	}
	else
		ft_putendl("error");
	return (0);
}
