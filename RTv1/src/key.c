#include <rtv1.h>

void		rt_event_light(int k, t_tool *t)
{
	if (k == 78)
		modif_all_lights(t, -0.55);
	else if (k == 69)
		modif_all_lights(t, 0.55);
	else if (k == 24)
		modif_lumamb(t, 0.25);
	else if (k == 27)
		modif_lumamb(t, -0.25);	
}

int		rt_event(int k, t_tool *t)
{
	if (k == 35)
	{
		t->rt->image->screen = malloc(sizeof(unsigned char) * (3 * t->rt->x_res * t->rt->y_res));
		t->rt->screenshot = 1;
		run_through(t);
		t->rt->screenshot = 0;
		free(t->rt->image->screen);
		t->rt->image->screen = NULL;
	}
	else if (k == 82 || k == 84 || k == 86 || k == 88
			|| k == 91 || k == 126 || k == 125 || k == 69 || k == 78
			|| k == 24 || k == 27)
	{
		rt_event_light(k, t);
		if (k == 82)
			t->rt->cam = t->rt->middlecams[4];
		else if (k == 84)
			t->rt->cam = t->rt->middlecams[0];
		else if (k == 86)
			t->rt->cam = t->rt->middlecams[1];
		else if (k == 88)
			t->rt->cam = t->rt->middlecams[2];
		else if (k == 91)
			t->rt->cam = t->rt->middlecams[3];
		else if (k == 126 && t->rt->cam->nb != 4)
			t->rt->cam = t->rt->upcams[t->rt->cam->nb];
		else if (k == 125 && t->rt->cam->nb != 4)
			t->rt->cam = t->rt->middlecams[t->rt->cam->nb];
		mlx_clear_window(t->mlx_ptr, t->rt->mlx_win);
		run_through(t);
	}
	if (k == 53)
	{
		mlx_destroy_window(t->mlx_ptr, t->rt->mlx_win);
		clean_rt(&t->rt);
	}
	return (0);
}

int		mouse_event(int keycode, int x, int y, t_tool *t)
{
	(void)(keycode);
	(void)(x);
	(void)(y);
	(void)(t);
	ft_putnbr(x);
	ft_putstr(" = x\n");
	ft_putnbr(y);
	ft_putstr(" = y\n");
	if (t->m->menu == 2)
	{
		if (x >= 60 && x <= 160 && y >= 150 && y <= 250)
		{
			launch("scenes/new", t);
		}
		if (x >= 260 && x <= 360 && y >= 150 && y <= 250)
		{
			launch("scenes/boat", t);
		}
		if (x >= 60 && x <= 160 && y >= 300 && y <= 400)
		{
			launch("scenes/room1", t);
		}
		if (x >= 260 && x <= 360 && y >= 300 && y <= 400)
		{
			launch("scenes/speciale", t);
		}
		if (x >= 60 && x <= 160 && y >= 450 && y <= 550)
		{
			launch("scenes/blackhole", t);
		}
		if (x >= 260 && x <= 360 && y >= 450 && y <= 550)
		{
			ft_putstr("test");
			launch("scenes/jungle", t);
		}
		if (x >= 160 && x <= 260 && y >= 50 && y <= 150)
		{
			system("open scenes/my_file");
			launch("scenes/my_file", t);
		}
		if (x >= 160 && x <= 260 && y >= 980 && y <= 1020)
		{
			print_group_menu(t);
		}

		if (x >= 160 && x <= 260 && y >= 1040 && y <= 1080)
			system("open https://www.youtube.com");
	}
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

int		menu_event(int keycode, t_tool *t)
{
    (void)(t);
	if (keycode == 53)
		exit(0);
	return (0);
}
