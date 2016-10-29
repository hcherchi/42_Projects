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

int		checkDigit(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		checkGrid(t_tool *tools, char *filename)
{
	char	*line;
	int		ret;
	int		fd;
	char	**split;

	line = NULL;
	fd = open(filename, O_RDONLY);
	tools->nbcol = 0;
	tools->nbline = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tools->nbline += 1;
		split = ft_strsplit(line, ' ');
		if (tools->nbcol == 0)
			tools->nbcol = ft_tablen(split);
		else
		{
			if (tools->nbcol != ft_tablen(split))
				return (-1);
		}
		if (checkDigit(split) == -1)
			return (-1);
	}
	close(fd);
	return (ret);
}

void	printGrid(t_tool *t)
{
	int i;
	int j;

	i = 0;
	while (i < t->nbline)
	{
		j = 0;
		while (j < t->nbcol)
		{
			ft_putnbr(t->grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	readLine(int i, t_tool *t)
{
	char	*line;
	int		j;
	char	**split;

	line = NULL;
	j = 0;
	get_next_line(t->fd, &line);
	split = ft_strsplit(line, ' ');
	t->grid[i] = (int *)malloc(sizeof(int) * t->nbcol);
	while (j < t->nbcol)
	{
		t->grid[i][j] = ft_atoi(split[j]);
		j++;
	}
}

void readGrid(char *file, t_tool *t)
{
	int i;

	t->fd = open(file, O_RDONLY);

	t->grid = (int **)malloc(sizeof(int*) * t->nbline);
	i = 0;
	while (i < t->nbline)
	{
		readLine(i, t);
		i++;
	}
}

void   init(t_tool *tools)
{
	t_point *pos;
	double miFOV;

	pos = malloc(sizeof(*pos));
	pos->x = 200;
	pos->y = 200;
	tools->pos = pos;
	tools->angle = -45;
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
	if (angle + inc > 180)
	{
		angle = angle + inc - 360;
	}
	else if (angle + inc <= - 180)
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
		tools->pos->x += cos(degreesToRadians(tools->angle)) * 5;
		tools->pos->y += - sin(degreesToRadians(tools->angle)) * 5;
		launch(tools);
	}
	else if (key == 125)
	{
		tools->pos->x += -cos(degreesToRadians(tools->angle)) * 5;
		tools->pos->y += sin(degreesToRadians(tools->angle)) * 5;
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
	printf("\nlines: %d\ncolumns: %d\n\n", tools->nbline, tools->nbcol);
	readGrid(file, tools);
	printGrid(tools);
	init(tools);
	ft_putendl("\n\n");
	ft_putendl("GO!");
	ft_putendl("\n\n");
	launch(tools);
	//mlx_key_hook(tools->mlx_win, keyPress, tools);
	mlx_hook(tools->mlx_win, 2, (1L<<0), keyPress, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
