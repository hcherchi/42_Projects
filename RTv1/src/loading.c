#include <rtv1.h>
#include <stdio.h>


// FAIRE UNE FONCTION QUI POSE LE BACKGROUND (TROP DE REPETITIONS)
//void screen_shot(t_tool *t)
//{
//    FILE *f;
//
//    f = fopen("save.jpg", "w");
//    fprintf(f, "P6 %d %d %d\n",(int)t->x_res,(int) t->y_res, 255);
//    fwrite(t->image->screen, 3, t->x_res * t->y_res, f);
//    fclose(f);
//}

void build_screen(t_tool *t)
{
    system("open scenes/my_file");
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
    mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2, t->m->x_res/2 -100, 0x0000CC00, "STEP 1 : BUILT AND SAVE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2, t->m->x_res/2 -70, 0x0000CC00, "STEP 2 : PRESS 'ENTER' TO LAUNCH YOUR SCENE");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF0000, "Press DELETE to go back to menu");
}
void info_screen(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
    mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->bg->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 -10, 0x0099FF00, "S : NEW - 3 spheres + 1 plan + 1 light");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 20, t->m->x_res/2 +70, 0x0099FF00, "F : MY_FILE - Create your own scene");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
}


void info_group(t_tool *t)
{
    mlx_clear_window(t->mlx_ptr, t->m->mlx_win);
    mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -100, 0x00CCCCCC, "RT/2016");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -50, 0x0099FF00, "Hugo Cherchi – hcherchi email: hcherchi@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 -10, 0x0099FF00, "Bruno Gantelmi – bgantelm email: bgantelm@student.42.fr // on est pas encore sur ");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 - 40, t->m->x_res/2 +30, 0x0099FF00, "Vincent Nguyen – vnguyen email: vnguyen@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -40, t->m->x_res/2 +70, 0x0099FF00, "Floren Henri – fhenri email: fhenri@student.42.fr");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Press DELETE to go back to menu");
}

void loading(t_tool *t)
{
    
    mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win, t->m->bg->mlx_img, -100, -100);
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -20, t->m->x_res/2 -100, 0x00CCCCCC, "RT : RAYTRACING PROJECT");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -20, t->m->x_res/2 -50, 0x0099FF00, "ENTER : START");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -20, t->m->x_res/2 -10, 0x0099FF00, "1 : SCENES");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -20, t->m->x_res/2 +30, 0x0099FF00, "2 : GROUP");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, t->m->y_res/2 -20, t->m->x_res/2 +70, 0x0099FF00, "3 : VIDEO");
    mlx_string_put(t->mlx_ptr, t->m->mlx_win, 50, 50, 0x00FF9966, "Version 1.2.8");
}
