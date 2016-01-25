/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/25 17:53:08 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_tool        	*tools;

	tools = malloc(sizeof(*tools));
	if (ac != 2)
	{
		ft_putendl("Bad number of arguments");
		return(1);
	}
	tools->mlx_ptr = mlx_init();
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, 640, 480, "I <3 FdF");
	if (fill_tools(tools, av[1]) == -1)
	{	
		ft_putendl("Invalid File");
		return (1);
	}
	launch_fdf(tools, av[1]);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
