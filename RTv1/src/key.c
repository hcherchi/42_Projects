#include <rtv1.h>

void	ester_egg(t_tool *t)
{
    t_image *texture;
    texture = malloc(sizeof(t_image));
    mlx_clear_window(t->mlx_ptr, t->mlx_win);
    
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/hugo.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, -100, -100);
}

void	menu_1(int keycode, t_tool *t)
{
    if (keycode == 36)
    {
        t->first = 1;
        t->which_menu = 3;
        parser(open("scenes/new", O_RDONLY), t);
        init_param(t);
        run_through(t);
    }
    if (keycode == 19 && t->go_back == 0)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 1;
        t->which_menu = 2;
        info_group(t);
    }
    if (keycode == 18 && t->go_back == 0)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 1;
        t->which_menu = 1;
        info_screen(t);
    }
    if(keycode == 20)
        system("open https://www.youtube.com");
    if (keycode == 64) //f17
        ester_egg(t);
}

void	menu_2(int keycode, t_tool *t)
{
    if (keycode == 0)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        parser(open("scenes/jail", O_RDONLY), t);
        if (t->error == 0)
        {
            init_param(t);
            run_through(t);
        }
        else
            t->which_menu = 5;
    }
    if (keycode == 1)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        parser(open("scenes/new", O_RDONLY), t);
        if (t->error == 0)
        {
            init_param(t);
            run_through(t);
        }
        else
            t->which_menu = 5;
    }
    if (keycode == 2)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        parser(open("scenes/all", O_RDONLY), t);
        if (t->error == 0)
        {
            init_param(t);
            run_through(t);
        }
        else
            t->which_menu = 5;
        
    }
    if (keycode == 3)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 4;
        build_screen(t);
    }
    if (keycode == 51)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

void	menu_3(int keycode, t_tool *t)
{
    if (keycode == 51)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

void		menu_4(int k, t_tool *t)
{
    if (k == 35)
    {
    t->image->screen = malloc(sizeof(unsigned char) * (3 *(int)t->x_res *(int)t->y_res));
        t->screen_shot = 1;
        run_through(t);
        t->screen_shot = 0;
        
    }
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
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

void menu_6 (int keycode, t_tool *t)
{
    affiche_error(t);
    if (keycode == 51)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        t->error = 0;
        loading(t);
    }
}
void menu_5(int keycode, t_tool *t)
{
    
    if (keycode == 36)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->first = 1;
        t->which_menu = 3;
        parser(open("scenes/my_file", O_RDONLY), t);
        if (t->error == 0)
        {
            init_param(t);
            run_through(t);
        }
        else
            t->which_menu = 5;
        
    }
    if (keycode == 51)
    {
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        t->go_back = 0;
        t->which_menu = 0;
        loading(t);
    }
}

int		event(int keycode, t_tool *t)
{
    if (keycode == 53 && t)
    {
        clean_tools(t);
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
