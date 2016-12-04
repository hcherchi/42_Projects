/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/12/04 13:10:18 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init(t_tool *t)
{
	t_point	*pos;
	float	mifov;

	pos = malloc(sizeof(*pos));
	pos->x = 10;
	pos->y = 10;
	t->pos = pos;
	t->angle = 0;
	t->fov = 60;
	mifov = t->fov / 2;
	t->width = 1000;
	t->height = 800;
	t->center_x = t->width / 2;
	t->center_y = t->height / 2;
	t->dist = (t->center_x / tan(D_TO_R(mifov)));
	t->inc_angle = t->fov / (float)t->width;
	t->cube = 100;
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->width, t->height, "<3 wolf");
}

int		main(void)
{
	t_tool	*tools;
	int		ret;

	tools = malloc(sizeof(*tools));
	ret = check_grid(tools, open("grid.txt", O_RDONLY));
	if (ret == -1 || tools->nbline < 1 || tools->nbcol < 1)
	{
		ft_putendl("Invalid map error");
		free(tools);
		exit(1);
	}
	read_grid(tools, open("grid.txt", O_RDONLY));
	init(tools);
	launch(tools);
	mlx_hook(tools->mlx_win, 2, (1L << 0), key_press, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
