#include <Rtv1.h>

void    init_param(t_tool *t)
{

	t->mlx_ptr = mlx_init();
	t->LumAmb = 0.2;
	t->cam->indent = 0.001;
	t->cam->dist = 1;
	t->cam->W = t->cam->x_res * t->cam->indent;
	t->cam->H = t->cam->y_res * t->cam->indent;

	t->mlx_win = mlx_new_window(t->mlx_ptr, t->cam->x_res, t->cam->y_res, "RTv1");
	t->mlx_img = mlx_new_image(t->mlx_ptr, t->cam->x_res, t->cam->y_res);

	t->image = malloc(sizeof(t_image));
	t->image->data = mlx_get_data_addr(t->mlx_img, &t->image->bpp, &t->image->size_line, &t->image->endian);

	t->cam->vect = vectorNew(0, 0, 1);
	t->cam->h_vect = vectorNew(0, 1, 0);
	t->cam->r_vect = vectorNew(1, 0, 0);

	t->cam->upleft = malloc(sizeof(t_pos));
	t->cam->upleft->x = t->cam->pos->x + t->cam->vect->x * t->cam->dist + t->cam->h_vect->x * (t->cam->H / 2) - t->cam->r_vect->x * (t->cam->W / 2);
	t->cam->upleft->y = t->cam->pos->y + t->cam->vect->y * t->cam->dist + t->cam->h_vect->y * (t->cam->H / 2) - t->cam->r_vect->y * (t->cam->W / 2);
	t->cam->upleft->z = t->cam->pos->z + t->cam->vect->z * t->cam->dist + t->cam->h_vect->z * (t->cam->H / 2) - t->cam->r_vect->z * (t->cam->W / 2);
}


void	run_through(t_tool *t)
{
    double x;
    double y;
    
    y = 0;
    while (y < t->cam->y_res)
    {
        x = 0;
        while (x < t->cam->x_res)
        {
            draw(t, x, y);
            x += 1;
        }
        y += 1;
    }
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}

int		main(int argc, char **argv)
{
	int     fd;
    t_tool *tools;

	if (argc != 2)
	{
		ft_putendl("Bad number of arguments");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error, file can't be open");
		return (1);
	}
	tools = parser(fd);
	init_param(tools);
	run_through(tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
