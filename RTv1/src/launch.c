/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:54:03 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:13:14 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	launch(char *scene, t_tool *tools)
{
	if (tools->rt)
	{
		if (tools->rt->mlx_win != NULL)
			mlx_destroy_window(tools->mlx_ptr, tools->rt->mlx_win);
		tools->rt = NULL;
	}
	parser(open(scene, O_RDONLY), tools);
	if (tools->error == 0)
	{
		init_param(tools);
		init_cams(tools);
		run_through(tools);
	}
	else
	{
		tools->error = 0;
		clean_rt(&tools->rt);
	}
}

void	init_param(t_tool *t)
{
	t->rt->indent = 0.001;
	t->rt->screenshot = 0;
	t->rt->sepia = 0;
	t->rt->w = t->rt->x_res * t->rt->indent;
	t->rt->h = t->rt->y_res * t->rt->indent;
	t->rt->dist = t->rt->w / (2 * tan((60 / 2) * (M_PI / 180)));
	t->rt->mlx_win = mlx_new_window(t->mlx_ptr,
		t->rt->x_res, t->rt->y_res, "RT");
	t->rt->image = malloc(sizeof(t_image));
	t->rt->image->mlx_img = mlx_new_image(t->mlx_ptr,
		t->rt->x_res, t->rt->y_res);
	t->rt->image->data = mlx_get_data_addr(t->rt->image->mlx_img,
			&t->rt->image->bpp,
		&t->rt->image->size_line, &t->rt->image->endian);
	t->rt->image->texture = NULL;
	t->rt->image->screen = NULL;
}

void	init_cams(t_tool *t)
{
	t->rt->mid = malloc(sizeof(t_cam*) * 5);
	t->rt->mid[0] = new_cam(vectornew(0, 0, -5), vectornew(0, 0, 1), t, 0);
	t->rt->mid[1] = new_cam(vectornew(-5, 0, 0), vectornew(1, 0, 0), t, 1);
	t->rt->mid[2] = new_cam(vectornew(5, 0, 0), vectornew(-1, 0, 0), t, 2);
	t->rt->mid[3] = new_cam(vectornew(0, 0, 5), vectornew(0, 0, -1), t, 3);
	if (t->rt->pos && t->rt->vect)
		t->rt->mid[4] = new_cam(t->rt->pos, t->rt->vect, t, 4);
	else
		t->rt->mid[4] = new_cam(vectornew(0, 2.5, -5),
		vectornew(0, -1, 2), t, 4);
	t->rt->up = malloc(sizeof(t_cam*) * 4);
	t->rt->up[0] = new_cam(vectornew(0, 2.5, -5), vectornew(0, -1, 2), t, 0);
	t->rt->up[1] = new_cam(vectornew(-5, 2.5, 0), vectornew(2, -1, 0), t, 1);
	t->rt->up[2] = new_cam(vectornew(5, 2.5, 0), vectornew(-2, -1, 0), t, 2);
	t->rt->up[3] = new_cam(vectornew(0, 2.5, 5), vectornew(0, -1, -2), t, 3);
	t->rt->cam = t->rt->mid[4];
}

void	put_image_to_file(t_tool *t)
{
	int	fd;

	system("rm -fr save.jpg");
	fd = open("save.jpg", O_WRONLY | O_CREAT);
	ft_putstr_fd("P6 ", fd);
	ft_putnbr_fd(t->rt->x_res, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(t->rt->y_res, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(255, fd);
	ft_putstr_fd("\n", fd);
	write(fd, t->rt->image->screen, ((t->rt->x_res * t->rt->y_res) +
				ft_strlen((char const *)t->rt->image->screen)) * 3);
	close(fd);
}

void	run_through_tools(t_tool *t)
{
	ft_verif(t, "textures/menu/barre.xpm");
	mlx_put_image_to_window(t->mlx_ptr, t->rt->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("textures/menu/barre.xpm"),
	&t->m->bg->width, &t->m->bg->height), 0, 0);
	mlx_key_hook(t->rt->mlx_win, rt_event, t);
	mlx_hook(t->rt->mlx_win, 17, (1L << 17), ft_exit2, t);
	mlx_mouse_hook(t->rt->mlx_win, mouse_event_rt, t);
}
