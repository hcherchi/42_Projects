/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:08 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 13:39:14 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	mouse_event_rt(int keycode, int x, int y, t_tool *t)
{
	if (keycode == 1 && x >= 19 && x <= 184 && y >= 17 && y <= 188)
	{
		if (x >= 126 && x <= 178 && y >= 64 && y <= 84)
		{
			t->rt->image->screen =
			malloc(sizeof(unsigned char) * (3 * t->rt->x_res * t->rt->y_res));
			t->rt->screenshot = 1;
			run_through(t);
			t->rt->screenshot = 0;
			free(t->rt->image->screen);
			t->rt->image->screen = NULL;
		}
		else
		{
			if (x >= 126 && x <= 169 && y >= 30 && y <= 53)
			{
				if (t->rt->sepia == 0)
					t->rt->sepia = 1;
				else
					t->rt->sepia = 0;
			}
			mouse_event_rt2(x, y, t);
		}
	}
	return (0);
}

int	rt_event(int k, t_tool *t)
{
	if (k == 53)
	{
		mlx_destroy_window(t->mlx_ptr, t->rt->mlx_win);
		clean_rt(&t->rt);
	}
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_tool *t)
{
	(void)(keycode);
	if (t->m->menu == 2)
		mouse_event2(x, y, t);
	if (t->m->menu == 1)
	{
		if (x >= 160 && x <= 231 && y >= 182 && y <= 268)
			system("open https://profile.intra.42.fr/users/hcherchi");
		if (x >= 160 && x <= 231 && y >= 382 && y <= 468)
			system("open https://profile.intra.42.fr/users/bgantelm");
		if (x >= 160 && x <= 231 && y >= 582 && y <= 668)
			system("open https://profile.intra.42.fr/users/vnguyen");
		if (x >= 160 && x <= 231 && y >= 782 && y <= 868)
			system("open https://profile.intra.42.fr/users/fhenri");
		if (x >= 111 && x <= 277 && y >= 920 && y <= 956)
		{
			print_scene_menu(t);
		}
	}
	return (0);
}

int	menu_event(int keycode, t_tool *t)
{
	(void)(t);
	if (keycode == 53)
		exit(0);
	return (0);
}
