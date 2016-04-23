#include <rtv1.h>

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
    else if (k == 82 || k == 84 || k == 86 || k == 87 || k == 88 || k == 91 || k == 126 || k == 125)
    {
        if (k == 82)
            t->rt->cam = t->rt->middlecams[5];
        else if (k == 84)
            t->rt->cam = t->rt->middlecams[0];
        else if (k == 86)
            t->rt->cam = t->rt->middlecams[1];
        else if (k == 87)
            t->rt->cam = t->rt->middlecams[4];
        else if (k == 88)
            t->rt->cam = t->rt->middlecams[2];
        else if (k == 91)
            t->rt->cam = t->rt->middlecams[3];
        else if (k == 126 && t->rt->cam->nb != 5)
            t->rt->cam = t->rt->upcams[t->rt->cam->nb];
        else if (k == 125 && t->rt->cam->nb != 5)
            t->rt->cam = t->rt->middlecams[t->rt->cam->nb];
        mlx_clear_window(t->mlx_ptr, t->rt->mlx_win);
        run_through(t);
    }
    if (k == 53)
    {
        mlx_destroy_window(t->mlx_ptr, t->rt->mlx_win);
        t->rt = NULL;
    }
    return (0);
}

void	start_menu(int keycode, t_tool *t)
{
    if (keycode == 19)
        print_group_menu(t);
    if (keycode == 18)
        print_scene_menu(t);
    if(keycode == 20)
        system("open https://www.youtube.com");
}

void	scene_menu(int keycode, t_tool *t)
{
    if (keycode == 18)
		launch("scenes/new", t);
	if (keycode == 19)
		launch("scenes/boat", t);
	if (keycode == 20)
		launch("scenes/room1", t);
	if (keycode == 21)
		launch("scenes/speciale", t);
    else if (keycode == 22)
    {
        system("open scenes/my_file");
        launch("scenes/my_file", t);
    }
}

int		menu_event(int keycode, t_tool *t)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	if (keycode == 51 && t->m->menu != 0)
		print_start_menu(t);
	if (t->m->menu == 0)
		start_menu(keycode, t);
	else if (t->m->menu == 2)
		scene_menu(keycode, t);
	return (0);
}
