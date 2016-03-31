#include <rtv1.h>
#include <stdio.h>

void screen_shot(t_tool *t)
{
    FILE *f;
    
    ft_putendl("salut le screen");
    f = fopen("save.jpg", "w");
    fprintf(f, "P6 %d %d %d\n",(int)t->x_res,(int) t->y_res, 255);
    fwrite(t->image->screen, 3, t->x_res * t->y_res, f);
    fclose(f);
}

void build_screen(t_tool *t)
{
    
    t_image *texture;
    texture = malloc(sizeof(t_image));
    
    system("open scenes/my_file");
    mlx_clear_window(t->mlx_ptr, t->mlx_win);
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/blue_background.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2, t->x_res/2 -100, 0x0000CC00, "1) build you scene and save the file");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2, t->x_res/2 -70, 0x0000CC00, "2)Presse 'ENTER' to lunch you scene");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 50, 0x00FF0000, "Presse DELETE to go back to menu");
}
void info_screen(t_tool *t)
{
    t_image *texture;
    texture = malloc(sizeof(t_image));
    mlx_clear_window(t->mlx_ptr, t->mlx_win);
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/blue_background.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 20, t->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 20, t->x_res/2 -50, 0x0099FF00, "A) Scene Jail: 2 spheres + 8 pillons 2 lights");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 20, t->x_res/2 -10, 0x0099FF00, "S) Scene new: 3 spheres + 1 plan + 1 light");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 20, t->x_res/2 +30, 0x0099FF00, "D) Scene all: all 4 objects + 1 light");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 20, t->x_res/2 +70, 0x0099FF00, "F) Create your own scene");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 50, 0x00FF9966, "Presse DELETE to go back to menu");
}


void info_group(t_tool *t)
{
    t_image *texture;
    texture = malloc(sizeof(t_image));
    mlx_clear_window(t->mlx_ptr, t->mlx_win);
    
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/blue_background.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 40, t->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 40, t->x_res/2 -50, 0x0099FF00, "Hugo Cherchi – hcherchi email: hcherchi@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 40, t->x_res/2 -10, 0x0099FF00, "Bruno Gantelmi – bgantelm email: bgantelm@student.42.fr // on est pas encore sur ");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 - 40, t->x_res/2 +30, 0x0099FF00, "Vincent Nguyen – vnguyen email: vnguyen@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -40, t->x_res/2 +70, 0x0099FF00, "Floren Henri – fhenri email: fhenri@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 50, 0x00FF9966, "Presse DELETE to go back to menu");
    free(texture);
}

void loading(t_tool *t)
{
    
    t_image *texture;
    texture = malloc(sizeof(t_image));
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, "textures/blue_background.xpm", &texture->width, &texture->height);
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    ft_putendl("TARACE");
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, texture->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -20, t->x_res/2 -100, 0x00CCCCCC, "Welcome to  RT:");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -20, t->x_res/2 -50, 0x0099FF00, "presse ENTER to start");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -20, t->x_res/2 -10, 0x0099FF00, "presse 1 to see info on the scene");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -20, t->x_res/2 +30, 0x0099FF00, "presse 2 to see info on the group");
    mlx_string_put(t->mlx_ptr, t->mlx_win, t->y_res/2 -20, t->x_res/2 +70, 0x0099FF00, "presse 3 to see the youtube video");
    mlx_string_put(t->mlx_ptr, t->mlx_win, 50, 50, 0x00FF9966, "Version 1.2.8");
    free(texture);
}
