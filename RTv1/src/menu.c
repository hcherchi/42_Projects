#include <rtv1.h>

void print_scene_menu(t_tool *t)
{
    t->m->bg = malloc(sizeof(t_image));
	t->m->bg->texture = ft_strdup("textures/menu/background3.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
    if (t->m->bg->mlx_img == NULL)
    {
        ft_putendl("Error, you are not allowed to lauch RT from this directory.");
        exit(0);
    }
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/point.xpm"), &t->m->bg->width, &t->m->bg->height),160, 45);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/new.xpm"), &t->m->bg->width, &t->m->bg->height),60, 150);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/boat.xpm"), &t->m->bg->width, &t->m->bg->height),240, 150);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/room.xpm"), &t->m->bg->width, &t->m->bg->height),60, 290);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/space-cylinder.xpm"), &t->m->bg->width, &t->m->bg->height),240, 290);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/blackhole.xpm"), &t->m->bg->width, &t->m->bg->height),60, 430);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/jungle.xpm"), &t->m->bg->width, &t->m->bg->height),240, 430);

 	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 570);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 570);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 720);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 720);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 870);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 870);
 	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/42.xpm"), &t->m->bg->width, &t->m->bg->height),160, 980);
 	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/youtube.xpm"), &t->m->bg->width, &t->m->bg->height),120, 1000);
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 120, 0x0099FF00, "NEW");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 120, 0x0099FF00, "BOAT");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 260, 0x0099FF00, "ROOM");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 260, 0x0099FF00, "SPACE-CYLINDER");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 400, 0x0099FF00, "BLACKHOLE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 400, 0x0099FF00, "JUNGLE");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 170, 20, 0x0099FF00, "CUSTOM");

	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 540, 0x0099FF00, "NaN");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 540, 0x0099FF00, "NaN");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 690, 0x0099FF00, "NaN");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 690, 0x0099FF00, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 840, 0x0099FF00, "NaN");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 840, 0x0099FF00, "NaN");
    t->m->menu = 2;
}


void print_group_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/background3.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, 0, 0);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/hcherchi.xpm"), &t->m->bg->width, &t->m->bg->height),160, 180);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/bgantelm.xpm"), &t->m->bg->width, &t->m->bg->height),160, 380);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/vnguyen.xpm"), &t->m->bg->width, &t->m->bg->height),160, 580);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/fhenri.xpm"), &t->m->bg->width, &t->m->bg->height),160, 780);
 	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/go_back.xpm"), &t->m->bg->width, &t->m->bg->height),100, 910);
 	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/copy.xpm"), &t->m->bg->width, &t->m->bg->height),120, 990);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 100, 0x0099FF00, "Hugo Cherchi - Hcherchi");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 130, 0x0099FF00, "hcherchi@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 300, 0x0099FF00, "Bruno Gantelmi - Bgantelm");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 330, 0x0099FF00, "bgantelm@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 500, 0x0099FF00, "Vincent Nguyen - Vnguyen");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 530, 0x0099FF00, "vnguyen@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 700, 0x0099FF00, "Floren Henri - Fhenri");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 730, 0x0099FF00, "fhenri@student.42.fr");
    t->m->menu = 1;
}

