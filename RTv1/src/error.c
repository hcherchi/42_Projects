#include <rtv1.h>

void	ft_error(t_tool * tools)
{
    tools->error = 1;
}

void affiche_error(t_tool *t)
{
    t_image *texture;
    
    mlx_clear_window(t->mlx_ptr, t->mlx_win);
    texture = malloc(sizeof(t_image));
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/error.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, 250, 125);
    mlx_string_put(t->mlx_ptr, t->mlx_win, 100, 100, 0x00CC6600, "Presse Dellet to go back" );
    free(texture);
}
