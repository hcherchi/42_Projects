#include <rtv1.h>

int     mouse_event_rt(int keycode, int x, int y, t_tool *t)
{
    ft_putnbr(x);
    ft_putstr(" = x\n");
    ft_putnbr(y);
    ft_putstr(" = y\n");
    if (keycode == 1 && x >= 19 && x <= 184 && y >= 17 && y <= 188)
    {
        if (x >= 126 && x <= 178 && y >= 64 && y <= 84) // picture
        {
            t->rt->image->screen = malloc(sizeof(unsigned char) * (3 * t->rt->x_res * t->rt->y_res));
            t->rt->screenshot = 1;
            run_through(t);
            t->rt->screenshot = 0;
            free(t->rt->image->screen);
            t->rt->image->screen = NULL;
        }
        else
        {
            if (x >= 126 && x <= 169 && y >= 30 && y <= 53) // sepia
            {
                if (t->rt->sepia == 0)
                    t->rt->sepia = 1;
                else
                    t->rt->sepia = 0;
            }
            if (x >= 29 && x <= 43 && y >= 39 && y <= 41)
                modif_all_lights(t, -0.10);
            if (x >= 90 && x <= 100 && y >= 35 && y <= 47)
                modif_all_lights(t, 0.10);
            if (x >= 30 && x <= 43 && y >= 77 && y <= 79)
                modif_lumamb(t, -0.10);
            if (x >= 83 && x <= 100 && y >= 73 && y <= 84)
                modif_lumamb(t, 0.10);
            if (x >= 52 && x <= 80 && y >= 105 && y <= 120) // touche haut
                t->rt->cam = t->rt->middlecams[3];
            if (x >= 23 && x <= 41 && y >= 131 && y <= 155) // touche de gauche
                t->rt->cam = t->rt->middlecams[2];
            if (x >= 92 && x <= 104 && y >= 131 && y <= 154) // touche de droite
                t->rt->cam = t->rt->middlecams[1];
            if (x >= 55 && x <= 79 && y >= 168 && y <= 177) // touche du bas
                t->rt->cam = t->rt->middlecams[0];
            if (x >= 54 && x <= 77 && y >= 132 && y <= 153) // touche du milieu
                t->rt->cam = t->rt->middlecams[4];
            if (x >= 125 && x <= 153 && y >= 113 && y <= 134  && t->rt->cam->nb != 4) // touche droite haute
                t->rt->cam = t->rt->upcams[t->rt->cam->nb];
            if (x >= 125 && x <= 153 && y >= 147 && y <= 172 && t->rt->cam->nb != 4) // touche droite bate
                t->rt->cam = t->rt->middlecams[t->rt->cam->nb];
            mlx_clear_window(t->mlx_ptr, t->rt->mlx_win);
            run_through(t);
        }
    }
    return (0);
}

int     rt_event(int k, t_tool *t)
{
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
