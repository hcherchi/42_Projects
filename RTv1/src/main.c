#include <rtv1.h>

int ft_exit2(t_tool *t)
{
	t->rt->mlx_win = NULL;
	return(0);
}

int	ft_exit(t_tool *t)
{
	(void)(t);
	exit(0);
	return (0);
}

int     main()
{
	t_tool *tools;

	tools = malloc(sizeof(t_tool));
	tools->m = malloc(sizeof(t_menu));
	tools->mlx_ptr = mlx_init();
	tools->rt = NULL;
    tools->m->x_res = 400;
    tools->m->y_res = 1100;
    tools->m->mlx_win = mlx_new_window(tools->mlx_ptr, tools->m->x_res, tools->m->y_res, "RT");
	print_scene_menu(tools);
    tools->m->bg->screen = NULL;
    tools->error = 0;
	mlx_key_hook(tools->m->mlx_win, menu_event, tools);
	mlx_mouse_hook(tools->m->mlx_win, mouse_event, tools);
	mlx_hook(tools->m->mlx_win, 17,(1L << 17),ft_exit,tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}
