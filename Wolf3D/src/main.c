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
	double miFOV;

	pos = malloc(sizeof(*pos));
	pos->x = 0;
	pos->y = 0;
	tools->pos = pos;
	tools->angle = 0;
	tools->FOV = 60;
	miFOV = tools->FOV / 2;
	tools->screenWidth = 1000;
	tools->screenHeight = 800;
	tools->centerX = tools->screenWidth / 2;
	tools->centerY = tools->screenHeight / 2;
	tools->dist = (tools->centerX / tan(degreesToRadians(miFOV)));
	tools->incAngle = tools->FOV / (double)tools->screenWidth;
	tools->cubeSize = 100;
	tools->mlx_ptr = mlx_init();
	tools->mlx_win = mlx_new_window(tools->mlx_ptr, tools->screenWidth, tools->screenHeight, "I <3 Wolf3D");
}

double adjustAngle(double angle, double inc)
{
	if (angle + inc >= 360)
	{
		angle = angle + inc - 360;
	}
	else if (angle + inc < 0)
	{
		angle = angle + inc + 360;
	}
	else
	{
		angle = angle + inc;
	}
	return angle;
}

int		keyPress(int key, t_tool *tools)
{
	if (key == 53)
		exit(0);
	else if (key == 123)
	{
		tools->angle = adjustAngle(tools->angle, 5);
		launch(tools);
	}
	else if (key == 124)
	{
		tools->angle = adjustAngle(tools->angle, -5);
		launch(tools);
	}
	else if (key == 126)
	{
		t_point *newPos;

		newPos = malloc(sizeof(*newPos));
		newPos->x = tools->pos->x + cos(degreesToRadians(tools->angle)) * 5;
		newPos->y = tools->pos->y - sin(degreesToRadians(tools->angle)) * 5;
		if (insideMap(newPos, tools))
		{
			tools->pos = newPos;
		}
		launch(tools);
	}
	else if (key == 125)
	{
		t_point *newPos;

		newPos = malloc(sizeof(*newPos));
		newPos->x = tools->pos->x - cos(degreesToRadians(tools->angle)) * 5;
		newPos->y = tools->pos->y + sin(degreesToRadians(tools->angle)) * 5;
		if (insideMap(newPos, tools))
		{
			tools->pos = newPos;
		}		
		launch(tools);
	}
	return (0);
}

int		main()
{
	t_tool	*tools;
	int ret;
	char *file;

	file = "grid.txt";
	tools = malloc(sizeof(*tools));
	ret = checkGrid(tools, file);
	if (ret == -1 || tools->nbline < 1 || tools->nbcol < 1)
	{
		ft_putendl("Invalid map error");
		exit(1);
	}

	readGrid(file, tools);
	init(tools);
	launch(tools);

	mlx_hook(tools->mlx_win, 2, (1L<<0), keyPress, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
