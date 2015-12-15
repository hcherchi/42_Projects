/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:25:37 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/09 13:51:35 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char *buf)
{
	int		nb;
	int		size;
	t_clean	*struct_pieces;
	char	**sol;

	if (test_general(buf) == 0)
	{
		nb = nb_pieces(buf);
		if (nb > 26)
		{
			ft_putstr("error\n");
			return ;
		}
		struct_pieces = init_struct(buf, nb);
		size = start_square(struct_pieces, nb);
		sol = init_sol(size);
		resol(sol, struct_pieces, nb, size);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fillit(test_file(av[1]));
	else
		ft_putstr("error\n");
	return (0);
}
