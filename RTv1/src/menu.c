#include <rtv1.h>

void print_build_menu(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
    system("open scenes/my_file");
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
    mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2, t->m->x_res/2 -100, 0x0000CC00, "STEP 1 : BUILT AND SAVE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2, t->m->x_res/2 -70, 0x0000CC00, "STEP 2 : PRESS 'ENTER' TO LAUNCH YOUR SCENE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF0000, "Press DELETE to go back to menu");
    t->m->menu = 3;
}
void print_scene_menu(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/rtmenu_minimal-61664251.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -10, 0x0099FF00, "1 : NEW - 3 spheres + 1 plan + 1 light");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +70, 0x0099FF00, "2 : MY_FILE - Create your own scene");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
    t->m->menu = 2;
}


void print_group_menu(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/rtmenu_minimal-61664251.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -50, 0x0099FF00, "Hugo Cherchi – hcherchi email: hcherchi@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -10, 0x0099FF00, "Bruno Gantelmi – bgantelm email: bgantelm@student.42.fr // on est pas encore sur ");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 +30, 0x0099FF00, "Vincent Nguyen – vnguyen email: vnguyen@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -40, t->m->x_res/2 +70, 0x0099FF00, "Floren Henri – fhenri email: fhenri@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
    t->m->menu = 1;
}

void print_start_menu(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/blue_background.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
    //mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 140, 0xFF9036, "RT : RAYTRACING PROJECT");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 160, 0xFFFFFFFF, "ENTER : START");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 180, 0xFFFFFFFF, "1 : SCENES");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 200, 0xFFFFFFFF, "2 : GROUP");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 220, 0xFFFFFFFF, "3 : VIDEO");
    //mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 95, 0xFFFFFFFF, "Version 1.2.8");
    t->m->menu = 0;
}

int ft_menu_mouse_handler(int x, int y, void *param)
{
	t_tool *t;

	t = (t_tool*)param;
	if (t->m->menu == 0)
	{
		if (x >= 35 && x <= 165 && y >= 166 && y <= 180)
			mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 160, 0x00E1FF, "ENTER : START");
		else if (x >= 35 && x <= 155 && y >= 186 && y <= 200)
			mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 180, 0x00E1FF, "1 : SCENES");
		else if (x >= 35 && x <= 155 && y >= 206 && y <= 220)
			mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 200, 0x00E1FF, "2 : GROUP");
		else if (x >= 35 && x <= 155 && y >= 226 && y <= 240)
			mlx_string_put(t->mlx_ptr, t->m->mlx_win, 35, 220, 0x00E1FF, "3 : VIDEO");
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
