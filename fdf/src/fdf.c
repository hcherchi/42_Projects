/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/24 20:27:23 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

typedef struct    data_s
{
	void          *mlx_ptr;
	void          *mlx_win;
}                 data_t;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

void	draw_line(t_point a, t_point b, data_t data)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
	
	i = 1;
	x = a.x;
	y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	xinc = (dx > 0) ? 1 : -1 ;
	yinc = (dy > 0) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 808080);
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 808080);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 808080);
			i++;
		}
	}
	
}

int	open_file(char *file)
{
	int fd;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	else
	{
		get_file(fd);
	}
}

int main(int ac, char **av)
{
	data_t        	data;

	if (ac != 2)
	{
		ft_putendl("Bad number of arguments");
		return(1);
	}
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "I <3 FdF")) == NULL)
		return (EXIT_FAILURE);
	if (open_file(av[1]) == -1)
	{
		ft_putendl("Not a valid file name").
		return (1);
	}
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
