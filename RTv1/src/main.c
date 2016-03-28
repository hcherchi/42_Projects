/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:36:23 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/28 12:24:01 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	update_cam(t_tool *t)
{
	t->cam->h_vect = vectornew(0, 1, 0);
	t->cam->r_vect = vectornew(t->cam->vect->z, 0, -1 * t->cam->vect->x);
	vectornorm(t->cam->r_vect);
	t->cam->upleft = malloc(sizeof(t_pos));
	t->cam->upleft->x = t->cam->pos->x + t->cam->vect->x * t->cam->dist
	+ t->cam->h_vect->x * (t->cam->h / 2) - t->cam->r_vect->x * (t->cam->w / 2);
	t->cam->upleft->y = t->cam->pos->y + t->cam->vect->y * t->cam->dist
	+ t->cam->h_vect->y * (t->cam->h / 2) - t->cam->r_vect->y * (t->cam->w / 2);
	t->cam->upleft->z = t->cam->pos->z + t->cam->vect->z * t->cam->dist
	+ t->cam->h_vect->z * (t->cam->h / 2) - t->cam->r_vect->z * (t->cam->w / 2);
}

void	init_param(t_tool *t)
{
	t->mlx_ptr = mlx_init();
	t->cam->indent = 0.001;
	t->cam->dist = 1;
	t->cam->w = t->cam->x_res * t->cam->indent;
	t->cam->h = t->cam->y_res * t->cam->indent;
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->cam->x_res,
	t->cam->y_res, "RTv1");
    t->image = malloc(sizeof(t_image));
    t->image->mlx_img = mlx_new_image(t->mlx_ptr, t->cam->x_res, t->cam->y_res);
    t->image->data = mlx_get_data_addr(t->image->mlx_img, &t->image->bpp,
                                       &t->image->size_line, &t->image->endian);
}

void	run_through(t_tool *t)
{
	int x;
	int y;

	update_cam(t);
	y = 0;
	while (y < t->cam->y_res)
	{
		x = 0;
		while (x < t->cam->x_res)
		{
			draw(t, x, y);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image->mlx_img, 0, 0);
}

void    init_texture(t_tool *e)
{
ft_putendl("2");
//   e->l_objects->texture = malloc(sizeof(t_image));
ft_putendl("3");
    e->l_objects->texture->mlx_img = mlx_xpm_file_to_image(e->mlx_ptr, e->l_objects->texture->texture, &e->l_objects->texture->width, &e->l_objects->texture->height);
ft_putendl("4");
    e->l_objects->texture->data = mlx_get_data_addr(e->l_objects->texture->mlx_img, &e->l_objects->texture->bpp, &e->l_objects->texture->size_line, &e->l_objects->texture->endian);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tool	*tools;

	if (argc != 2)
	{
        ft_putnbr(argc);
		ft_putendl("Bad number of arguments");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	tools = malloc(sizeof(t_tool));
	parser(fd, tools);
	init_param(tools);
	ft_putendl(tools->l_objects->texture->texture);
	if (tools->l_objects->texture->texture)
	{
		init_texture(tools);
	}
	run_through(tools);
	mlx_key_hook(tools->mlx_win, event, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
