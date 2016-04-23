#include <rtv1.h>

void print_scene_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/rtmenu_minimal-61664251.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
<<<<<<< HEAD
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -10, 0x0099FF00, "1 : NEW - 3 spheres + 1 plan + 1 light");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +30, 0x0099FF00, "2 :Boat - 1 sphere + 1 skybox");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +60, 0x0099FF00, "3 :Rool1 - 1 sphere + 5 plan + texture");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +90, 0x0099FF00, "4 :Speciale");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +120, 0x0099FF00, "5 : MY_FILE - Create your own scene");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
	t->m->menu = 2;
=======
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 100, 0x0099FF00, "1 : NEW");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 150, 0x0099FF00, "2 : BOAT");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 200, 0x0099FF00, "3 : ROOM");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 250, 0x0099FF00, "4 : SPECIALE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 300, 0x0099FF00, "5 : MY_FILE - Create your own scene");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 550, 0x00FF9966, "Press DELETE to go back to menu");
    t->m->menu = 2;
>>>>>>> f25d8d3de10144e13ecec3937462494c1df6c2c8
}


void print_group_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/rtmenu_minimal-61664251.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
<<<<<<< HEAD
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, t->m->x_res/2 -50, 0x0099FF00, "Hugo Cherchi – hcherchi email: hcherchi@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, t->m->x_res/2 -10, 0x0099FF00, "Bruno Gantelmi – bgantelm email: bgantelm@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, t->m->x_res/2 +30, 0x0099FF00, "Vincent Nguyen – vnguyen email: vnguyen@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, t->m->x_res/2 +70, 0x0099FF00, "Floren Henri – fhenri email: fhenri@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
	t->m->menu = 1;
=======
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 100, 0x0099FF00, "Hugo Cherchi - Hcherchi");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 130, 0x0099FF00, "hcherchi@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 200, 0x0099FF00, "Bruno Gantelmi - Bgantelm");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 230, 0x0099FF00, "bgantelm@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 300, 0x0099FF00, "Vincent Nguyen - Vnguyen");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 330, 0x0099FF00, "vnguyen@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 400, 0x0099FF00, "Floren Henri - Fhenri");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 430, 0x0099FF00, "fhenri@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 20, 550, 0x00FF9966, "Press DELETE to go back to menu");
    t->m->menu = 1;
>>>>>>> f25d8d3de10144e13ecec3937462494c1df6c2c8
}

void print_start_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/blue_background.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
	//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 180, 0xFFFFFFFF, "1 : SCENES");
	//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 200, 0xFFFFFFFF, "2 : GROUP");
	//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 220, 0xFFFFFFFF, "3 : VIDEO");
	t->m->menu = 0;
}

void	start_menu_hover(t_tool *t, int choice)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	if (choice == 1)
		t->m->bg->texture = ft_strdup("textures/menu/menu_hover_1.xpm");
	else if (choice == 2)
		t->m->bg->texture = ft_strdup("textures/menu/menu_hover_2.xpm");
	else if (choice == 3)
		t->m->bg->texture = ft_strdup("textures/menu/menu_hover_3.xpm");
	else
		return;
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
}

int ft_menu_mouse_handler(int x, int y, void *param)
{
	t_tool *t;

	t = (t_tool*)param;
	if (t->m->menu == 0)
	{
		if (x >= 35 && x <= 155 && y >= 186 && y <= 200)
			start_menu_hover(t, 1);
			//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 180, 0x00E1FF, "1 : SCENES");
		else if (x >= 35 && x <= 155 && y >= 206 && y <= 220)
			start_menu_hover(t, 2);
			//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 200, 0x00E1FF, "2 : GROUP");
		else if (x >= 35 && x <= 155 && y >= 226 && y <= 240)
			start_menu_hover(t, 3);
			//mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 220, 0x00E1FF, "3 : VIDEO");
		else
			print_start_menu(t);
	}
	return (1);
}

int	ft_menu_click_handler(int keycode, int x, int y, t_tool *t)
{
	if (keycode != 1)
		return (1);
	if (x >= 35 && x <= 165 && y >= 186 && y <= 200)
		print_scene_menu(t);
	else if (x >= 35 && x <= 165 && y >= 206 && y <= 220)
		print_group_menu(t);
	else if (x >= 35 && x <= 165 && y >= 226 && y <= 240)
		system("open https://www.youtube.com");
	return (0);
}
