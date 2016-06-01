/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:54:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 15:12:00 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int			ft_verif(t_tool *t, char *verife)
{
	void *mlx_img;

	mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, verife,
			&t->m->bg->width, &t->m->bg->height);
	if (mlx_img == NULL)
	{
		ft_putendl("messing file");
		exit(0);
	}
	return (1);
}

void		print_scene_menu1(t_tool *t)
{
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 120, 0x00fcf3f0, "BOAT");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 260, 0x00fcf3f0, "ROOM");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 260,
			0x00fcf3f0, "SPACE-CYLINDER");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 400,
			0x00fcf3f0, "BLACKHOLE");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win,
	240, 400, 0x00fcf3f0, "ILLUMINATE");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 955, 0x00fcf3f0, "CUSTOM");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 540, 0x00fcf3f0, "ECHIQUIER");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 540, 0x00fcf3f0, "SOLAR");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 680, 0x00fcf3f0, "FORMS");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 680, 0x00fcf3f0, "PYRENEES");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 820, 0x00fcf3f0, "POKEBALL");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 820, 0x00fcf3f0, "PETANQUE");
}

void		print_scene_menu(t_tool *t)
{
	t->m->bg = malloc(sizeof(t_image));
	t->m->bg->texture = ft_strdup("textures/menu/background3.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr,
			t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	if (t->m->bg->mlx_img == NULL)
	{
		ft_putendl("Error, you are not allowed to lauch RT.");
		exit(0);
	}
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img,
			&t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
			t->m->bg->mlx_img, -500, -300);
	print_suite(t);
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 120, 0x00fcf3f0, "NEW");
	print_scene_menu1(t);
	t->m->menu = 2;
}

void		print_group_menu1(t_tool *t)
{
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 100,
			0x00fcf3f0, "Hugo Cherchi - Hcherchi");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 130,
			0x00fcf3f0, "hcherchi@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 300,
			0x00fcf3f0, "Bruno Gantelmi - Bgantelm");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 330,
			0x00fcf3f0, "bgantelm@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 500,
			0x00fcf3f0, "Vincent Nguyen - Vnguyen");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 530,
			0x00fcf3f0, "vnguyen@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 700,
			0x00fcf3f0, "Floren Henri - Fhenri");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 730,
			0x00fcf3f0, "fhenri@student.42.fr");
}

void		print_group_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/background3.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr,
			t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img,
			&t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
			t->m->bg->mlx_img, -500, -300);
	print_groupe1(t);
	print_group_menu1(t);
	t->m->menu = 1;
}
