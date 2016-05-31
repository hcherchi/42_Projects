#include <rtv1.h>

int ft_verif(t_tool *t , char *verife)
{
	void *mlx_img;

	mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, verife, &t->m->bg->width, &t->m->bg->height);
	if (mlx_img == NULL)
	{
		ft_putendl("messing file");
		exit(0);
	}
	return (1);
}

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
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, -500, -300);

	ft_verif(t,ft_strdup("miniature/point.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/point.xpm"), &t->m->bg->width, &t->m->bg->height),60, 980);
	ft_verif(t,ft_strdup("miniature/new.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/new.xpm"), &t->m->bg->width, &t->m->bg->height),60, 150);
	ft_verif(t,ft_strdup("miniature/boat.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/boat.xpm"), &t->m->bg->width, &t->m->bg->height),240, 150);
	ft_verif(t,ft_strdup("miniature/room.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/room.xpm"), &t->m->bg->width, &t->m->bg->height),60, 290);
	ft_verif(t,ft_strdup("miniature/space-cylinder.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/space-cylinder.xpm"), &t->m->bg->width, &t->m->bg->height),240, 290);
	ft_verif(t,ft_strdup("miniature/blackhole.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/blackhole.xpm"), &t->m->bg->width, &t->m->bg->height),60, 430);
	ft_verif(t,ft_strdup("miniature/jungle.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/jungle.xpm"), &t->m->bg->width, &t->m->bg->height),240, 430);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 570);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 570);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 710);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 710);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),60, 850);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/not-found.xpm"), &t->m->bg->width, &t->m->bg->height),240, 850);
	ft_verif(t,ft_strdup("miniature/not-found.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/42.xpm"), &t->m->bg->width, &t->m->bg->height),250, 980);
	ft_verif(t,ft_strdup("miniature/youtube.xpm.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/youtube.xpm"), &t->m->bg->width, &t->m->bg->height),210, 1000);
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 120, 0x00fcf3f0, "NEW");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 120, 0x00fcf3f0, "BOAT");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 260, 0x00fcf3f0, "ROOM");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 260, 0x00fcf3f0, "SPACE-CYLINDER");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 400, 0x00fcf3f0, "BLACKHOLE");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 400, 0x00fcf3f0, "JUNGLE");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 955, 0x00fcf3f0, "CUSTOM");

	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 540, 0x00fcf3f0, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 540, 0x00fcf3f0, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 680, 0x00fcf3f0, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 680, 0x00fcf3f0, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 60, 820, 0x00fcf3f0, "NaN");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 240, 820, 0x00fcf3f0, "NaN");
	t->m->menu = 2;
}


void print_group_menu(t_tool *t)
{
	mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
	t->m->bg->texture = ft_strdup("textures/menu/background3.xpm");
	t->m->bg->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, t->m->bg->texture, &t->m->bg->width, &t->m->bg->height);
	t->m->bg->data = mlx_get_data_addr(t->m->bg->mlx_img, &t->m->bg->bpp, &t->m->bg->size_line, &t->m->bg->endian);
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, -500, -300);
	ft_verif(t,ft_strdup("miniature/hcherchi.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/hcherchi.xpm"), &t->m->bg->width, &t->m->bg->height),160, 180);
	ft_verif(t,ft_strdup("miniature/bgantelm.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/bgantelm.xpm"), &t->m->bg->width, &t->m->bg->height),160, 380);
	ft_verif(t,ft_strdup("miniature/vnguyen.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/vnguyen.xpm"), &t->m->bg->width, &t->m->bg->height),160, 580);
	ft_verif(t,ft_strdup("miniature/fhenri.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/fhenri.xpm"), &t->m->bg->width, &t->m->bg->height),160, 780);
	ft_verif(t,ft_strdup("miniature/go_back.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/go_back.xpm"), &t->m->bg->width, &t->m->bg->height),100, 910);
	ft_verif(t,ft_strdup("miniature/copy.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,  mlx_xpm_file_to_image(t->mlx_ptr,ft_strdup("miniature/copy.xpm"), &t->m->bg->width, &t->m->bg->height),150, 1000);
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 100, 0x00fcf3f0, "Hugo Cherchi - Hcherchi");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 130, 0x00fcf3f0, "hcherchi@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 300, 0x00fcf3f0, "Bruno Gantelmi - Bgantelm");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 330, 0x00fcf3f0, "bgantelm@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 500, 0x00fcf3f0, "Vincent Nguyen - Vnguyen");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 530, 0x00fcf3f0, "vnguyen@student.42.fr");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 700, 0x00fcf3f0, "Floren Henri - Fhenri");
	mlx_string_put(t->mlx_ptr, t->m->mlx_win, 80, 730, 0x00fcf3f0, "fhenri@student.42.fr");
	t->m->menu = 1;
}

