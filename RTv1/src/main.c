#include <rtv1.h>
#include <stdio.h>
#include <pthread.h>

void	init_param(t_tool *t)
{
    t->screen_shot = 0;
    t->yes = 0;
    t->go_back = 0;
	t->indent = 0.001;
    t->w = t->x_res * t->indent;
    t->h = t->y_res * t->indent;
	t->dist = t->w / (2 * tan((60 / 2) * (M_PI / 180)));
    if (t->first == 0)
    {
        t->mlx_win = mlx_new_window(t->mlx_ptr, t->x_res, t->y_res, "RTv1");
        t->image = malloc(sizeof(t_image));
        t->image->mlx_img = mlx_new_image(t->mlx_ptr, t->x_res, t->y_res);
        t->image->data = mlx_get_data_addr(t->image->mlx_img, &t->image->bpp,
                                       &t->image->size_line, &t->image->endian);
    }
    t->sky = fill_texture("textures/sky.xpm", t);
}

void run_through(t_tool *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->y_res)
	{
		x = 0;
		while (x < t->x_res)
		{
			draw(t, x, y);
			x += 1;
		}
		y += 1;
	}
    if (t->screen_shot == 0)
        mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image->mlx_img, 0, 0);
    else
        screen_shot(t);
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 25, 0x009933FF, "Use arrow key-bind to move");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 50, 0x009933FF, "Use 'P' to take a picture");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 75, 0x009933FF, "Use 'DELETE' to go back menu");
}

t_cam *new_cam(t_pos *pos, t_pos *vect, t_tool *t, int nb)
{
    t_cam *cam;
    
    vectornorm(vect);
    cam = malloc(sizeof(t_cam));
    cam->vect = vect;
    cam->pos = pos;
    cam->r_vect = malloc(sizeof(t_pos));
    cam->r_vect->x = cam->vect->z;
    cam->r_vect->y = 0;
    cam->r_vect->z = - 1 * cam->vect->x;
    if (cam->vect->x == 0 && cam->vect->z == 0)
        cam->r_vect->x = 1;
    cam->h_vect = malloc(sizeof(t_pos));
    cam->h_vect->x = -cam->r_vect->y * cam->vect->z + cam->r_vect->z * cam->vect->y;
    cam->h_vect->y = -cam->r_vect->z * cam->vect->x + cam->r_vect->x * cam->vect->z;
    cam->h_vect->z = -cam->r_vect->x * cam->vect->y + cam->r_vect->y * cam->vect->x;
    vectornorm(cam->r_vect);
    vectornorm(cam->h_vect);
    cam->upleft = malloc(sizeof(t_pos));
    cam->upleft->x = cam->pos->x + cam->vect->x * t->dist + cam->h_vect->x * (t->h / 2) - cam->r_vect->x * (t->w / 2);
    cam->upleft->y = cam->pos->y + cam->vect->y * t->dist+ cam->h_vect->y * (t->h / 2) - cam->r_vect->y * (t->w / 2);
    cam->upleft->z = cam->pos->z + cam->vect->z * t->dist+ cam->h_vect->z * (t->h / 2) - cam->r_vect->z * (t->w / 2);
    cam->nb = nb;
    return (cam);
}

void    init_cams(t_tool *t)
{
    t->middlecams = malloc(sizeof(t_cam*) * 6);
    t->middlecams[0] = new_cam(vectornew(0, 0, -5), vectornew(0, 0, 1), t, 0);
    t->middlecams[1] = new_cam(vectornew(-5, 0, 0), vectornew(1, 0, 0), t, 1);
    t->middlecams[2] = new_cam(vectornew(5, 0, 0), vectornew(-1, 0, 0), t, 2);
    t->middlecams[3] = new_cam(vectornew(0, 0, 5), vectornew(0, 0, -1), t, 3);
    t->middlecams[4] = new_cam(vectornew(0, 5, 0), vectornew(0, -1, 0), t, 4);
    if (t->pos && t->vect)
        t->middlecams[5] = new_cam(t->pos, t->vect, t, 5);
    else
        t->middlecams[5] = new_cam(vectornew(0, 2.5, -5), vectornew(0, -1, 2), t, 5);
    t->upcams = malloc(sizeof(t_cam*) * 5);
    t->upcams[0] = new_cam(vectornew(0, 2.5, -5), vectornew(0, -1, 2), t, 0);
    t->upcams[1] = new_cam(vectornew(-5, 2.5, 0), vectornew(2, -1, 0), t, 1);
    t->upcams[2] = new_cam(vectornew(5, 2.5, 0), vectornew(-2, -1, 0), t, 2);
    t->upcams[3] = new_cam(vectornew(0, 2.5, 5), vectornew(0, -1, -2), t, 3);
    t->upcams[4] = new_cam(vectornew(0, 10, 0), vectornew(0, -1, 0), t, 4);
    t->cam = t->middlecams[5];
}

int		main(void)
{
	t_tool	*tools;

    tools = malloc(sizeof(t_tool));
    tools->first = 0;
    tools->error = 0;
    tools->which_menu = 0;
	parser(open("scenes/new", O_RDONLY), tools);
	init_param(tools);
    init_cams(tools);
    loading(tools);
	mlx_key_hook(tools->mlx_win, event, tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
