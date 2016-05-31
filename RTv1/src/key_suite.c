#include <rtv1.h>

void			mouse_event_rt2(int x, int y, t_tool *t)
{
	if (x >= 29 && x <= 43 && y >= 39 && y <= 41)
		modif_all_lights(t, -0.10);
	if (x >= 90 && x <= 100 && y >= 35 && y <= 47)
		modif_all_lights(t, 0.10);
	if (x >= 30 && x <= 43 && y >= 77 && y <= 79)
		modif_lumamb(t, -0.10);
	if (x >= 83 && x <= 100 && y >= 73 && y <= 84)
		modif_lumamb(t, 0.10);
	if (x >= 52 && x <= 80 && y >= 105 && y <= 120)
		t->rt->cam = t->rt->middlecams[3];
	if (x >= 23 && x <= 41 && y >= 131 && y <= 155)
		t->rt->cam = t->rt->middlecams[2];
	if (x >= 92 && x <= 104 && y >= 131 && y <= 154)
		t->rt->cam = t->rt->middlecams[1];
	if (x >= 55 && x <= 79 && y >= 168 && y <= 177)
		t->rt->cam = t->rt->middlecams[0];
	if (x >= 54 && x <= 77 && y >= 132 && y <= 153)
		t->rt->cam = t->rt->middlecams[4];
	if (x >= 125 && x <= 153 && y >= 113 && y <= 134 && t->rt->cam->nb != 4)
		t->rt->cam = t->rt->upcams[t->rt->cam->nb];
	if (x >= 125 && x <= 153 && y >= 147 && y <= 172 && t->rt->cam->nb != 4)
		t->rt->cam = t->rt->middlecams[t->rt->cam->nb];
	mlx_clear_window(t->mlx_ptr, t->rt->mlx_win);
	run_through(t);
}

void			mouse_event2(int x, int y, t_tool *t)
{
	if (x >= 60 && x <= 160 && y >= 150 && y <= 250)
		launch("scenes/new", t);
	if (x >= 260 && x <= 360 && y >= 150 && y <= 250)
		launch("scenes/boat", t);
	if (x >= 60 && x <= 160 && y >= 300 && y <= 400)
		launch("scenes/room1", t);
	if (x >= 260 && x <= 360 && y >= 300 && y <= 400)
		launch("scenes/speciale", t);
	if (x >= 60 && x <= 160 && y >= 450 && y <= 550)
		launch("scenes/blackhole", t);
	if (x >= 260 && x <= 360 && y >= 450 && y <= 550)
		launch("scenes/jungle", t);
	if (x >= 63 && x <= 160 && y >= 980 && y <= 1080)
	{
		system("open scenes/my_file");
		launch("scenes/my_file", t);
	}
	if (x >= 250 && x <= 310 && y >= 980 && y <= 1020)
		print_group_menu(t);
	if (x >= 250 && x <= 310 && y >= 1030 && y <= 1075)
		system("open https://www.youtube.com");
}
