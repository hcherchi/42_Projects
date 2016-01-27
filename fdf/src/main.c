/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/27 19:53:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_win_size(t_tool *tools)
{
	float coef;
	
	coef = (float)tools->nbline / (float)tools->nbcol;
	if (2560 * coef > 1400)
	{
		tools->hwin = 1400;
		tools->wwin = 1400 / coef;
	}
	else
	{
		tools->wwin = 2560;
		tools->hwin = 2560 * coef;
	}
}

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
	if (fill_tools(tools, av[1]) == -1)
	{
		ft_putendl("Invalid File");
		return (1);
	}
	tools->fd = open(av[1], O_RDONLY);
	find_win_size(tools);
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, 2560, 1400, "I <3 FdF");
	launch_fdf(tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
