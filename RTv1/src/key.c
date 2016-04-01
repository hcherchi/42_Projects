#include <rtv1.h>

void		rt_event(int k, t_tool *t)
{
    //    if (k == 35)
    //    {
    //    t->image->screen = malloc(sizeof(unsigned char) * (3 *(int)t->x_res *(int)t->y_res));
    //        t->screen_shot = 1;
    //        run_through(t);
    //        t->screen_shot = 0;
    //
    //    }
    else if (k == 82 || k == 84 || k == 86 || k == 87 || k == 88 || k == 91 || k == 126 || k == 125)
    {
        if (k == 82)
            t->cam = t->middlecams[5];
        else if (k == 84)
            t->cam = t->upcams[0];
        else if (k == 86)
            t->cam = t->upcams[1];
        else if (k == 87)
            t->cam = t->upcams[4];
        else if (k == 88)
            t->cam = t->upcams[2];
        else if (k == 91)
            t->cam = t->upcams[3];
        else if (k == 126 && t->cam->nb != 5)
            t->cam = t->upcams[t->cam->nb];
        else if (k == 125 && t->cam->nb != 5)
            t->cam = t->middlecams[t->cam->nb];
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        run_through(t);
    }
    if (k == 51)
        mlx_destroy_window(t->mlx_ptr, t->mlx_win);
}

void menu_6 (int keycode, t_menu *t)
{
    affiche_error(t);
    if (keycode == 51)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        t->error = 0;
        loading(t);
    }
}


void	menu_1(int keycode, t_menu *t)
{
    if (keycode == 36)
    {
        t->first = 1;
        t->which_menu = 3;
        launch("scenes/new");
    }
    if (keycode == 19 && t->go_back == 0)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 1;
        t->which_menu = 2;
        info_group(t);
    }
    if (keycode == 18 && t->go_back == 0)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 1;
        t->which_menu = 1;
        info_screen(t);
    }
    if(keycode == 20)
        system("open https://www.youtube.com");
}

void	menu_2(int keycode, t_menu *t)
{
    if (keycode == 1)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        launch("scenes/new");
    }
    if (keycode == 3)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 4;
        build_screen(t);
    }
    if (keycode == 51)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

void	menu_3(int keycode, t_menu *t)
{
    if (keycode == 51)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

void menu_5(int keycode, t_menu *t)
{
    
    if (keycode == 36)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        launch("scenes/my_file");
    }
    if (keycode == 51)
    {
        mlx_clear_window(mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

int		menu_event(int keycode, t_menu *t)
{
    if (keycode == 53 && t)
    {
        exit(0);
    }
    if(t->which_menu == 0)
        menu_1(keycode, t);
    if (t->which_menu == 1)
        menu_2(keycode, t);
    if (t->which_menu == 2)
        menu_3(keycode, t);
    if (t->which_menu == 3)
        menu_4(keycode, t); 
    if (t->which_menu == 4)
        menu_5(keycode, t); 
    if (t->which_menu == 5)
        menu_6(keycode, t);
    return (0);
}
