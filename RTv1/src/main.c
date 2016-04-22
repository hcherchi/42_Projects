#include <rtv1.h>

void    init_menu(t_tool *tools)
{
    tools->m->x_res = 800;
    tools->m->y_res = 600;
    tools->m->mlx_win = mlx_new_window(tools->mlx_ptr, tools->m->x_res, tools->m->y_res, "RT");
    tools->m->bg = malloc(sizeof(t_image));
    tools->m->bg->texture = ft_strdup("textures/blue_background.xpm");
    tools->m->bg->mlx_img = mlx_xpm_file_to_image(tools->mlx_ptr, tools->m->bg->texture, &tools->m->bg->width, &tools->m->bg->height);
    if (tools->m->bg->mlx_img == NULL)
    {
        ft_putendl("Error, you are not allowed to lauch RT from this directory.");
        exit(0);
    }
    tools->m->bg->data = mlx_get_data_addr(tools->m->bg->mlx_img, &tools->m->bg->bpp, &tools->m->bg->size_line, &tools->m->bg->endian);
    tools->m->bg->screen = NULL;
    tools->error = 0;
    tools->no_error = 0;
}

int     main()
{
    t_tool *tools;
    
    tools = malloc(sizeof(t_tool));
    tools->m = malloc(sizeof(t_menu));
    tools->mlx_ptr = mlx_init();
    tools->rt = NULL;
    init_menu(tools);
    print_start_menu(tools);
    mlx_key_hook(tools->m->mlx_win, menu_event, tools);
    mlx_loop(tools->mlx_ptr);
    return (0);
}
