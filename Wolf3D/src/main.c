/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void   init(t_tool *tools)
{
	t_point *pos;
	float miFOV;

	pos = malloc(sizeof(*pos));
	pos->x = 10;
	pos->y = 10;
	tools->pos = pos;
	tools->angle = 0;
	tools->FOV = 60;
	miFOV = tools->FOV / 2;
	tools->screenWidth = 1000;
	tools->screenHeight = 800;
	tools->centerX = tools->screenWidth / 2;
	tools->centerY = tools->screenHeight / 2;
	tools->dist = (tools->centerX / tan(degreesToRadians(miFOV)));
	tools->incAngle = tools->FOV / (float)tools->screenWidth;
	tools->cubeSize = 100;
	tools->mlx_ptr = mlx_init();
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, tools->screenWidth, tools->screenHeight, "I <3 Wolf3D");
}

int		main()
{
	t_tool	*tools;
	int ret;

	tools = malloc(sizeof(*tools));
	ret = checkGrid(tools, open("grid.txt", O_RDONLY));
	if (ret == -1 || tools->nbline < 1 || tools->nbcol < 1)
	{
		ft_putendl("Invalid map error");
		free(tools);
		exit(1);
	}
	readGrid(tools, open("grid.txt", O_RDONLY));
	init(tools);
	launch(tools);
	mlx_hook(tools->mlx_win, 2, (1L<<0), keyPress, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
