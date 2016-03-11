#include <RTv1.h>
#include <stdio.h>

t_tool    *init_param()
{
    t_tool *t;
    
    t = malloc(sizeof(*t));
    
    t->mlx_ptr = mlx_init();
    
    t->cam.dist = 1;
    t->cam.W = 1;
    t->cam.H = 0.8;
    t->cam.x_res = 1000;
    t->cam.y_res = 800;
    
    t->mlx_win = mlx_new_window(t->mlx_ptr, t->cam.x_res, t->cam.y_res, "RTv1");
    t->mlx_img = mlx_new_image(t->mlx_ptr, t->cam.x_res, t->cam.y_res);
    
    t->cam.pos.x = 0.1;
    t->cam.pos.y = 0;
    t->cam.pos.z = 0;
    
    t->cam.vect.x = 0;
    t->cam.vect.y = 0;
    t->cam.vect.z = 1;
    
    t->cam.h_vect.x = 0;
    t->cam.h_vect.y = 1;
    t->cam.h_vect.z = 0;
    
    t->cam.r_vect.x = 1;
    t->cam.r_vect.y = 0;
    t->cam.r_vect.z = 0;
    
    t->cam.upleft.x = t->cam.pos.x + t->cam.vect.x * t->cam.dist + t->cam.h_vect.x * (t->cam.H / 2) - t->cam.r_vect.x * (t->cam.W / 2);
    t->cam.upleft.y = t->cam.pos.y + t->cam.vect.y * t->cam.dist + t->cam.h_vect.y * (t->cam.H / 2) - t->cam.r_vect.y * (t->cam.W / 2);
    t->cam.upleft.z = t->cam.pos.z + t->cam.vect.z * t->cam.dist + t->cam.h_vect.z * (t->cam.H / 2) - t->cam.r_vect.z * (t->cam.W / 2);
    
    t->cam.x_indent = t->cam.W / t->cam.x_res;
    t->cam.y_indent = t->cam.H / t->cam.y_res;
    
    //printf("x = %f / y = %f / z = %f\n",t->cam.upleft.x, t->cam.upleft.y, t->cam.upleft.z);
    return (t);
}


void	run_through(t_tool *t)
{
    float x;
    float y;
    
    x = 0;
    while (x < t->cam.x_res)
    {
        y = 0;
        while (y < t->cam.y_res)
        {
            draw(t, x, y);
            y += 1;
        }
        x += 1;
    }
    mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->mlx_img, 0, 0);
}

int		main(void)
{
	t_tool	*tools;
    
    tools = init_param();
    run_through(tools);
	mlx_loop(tools->mlx_ptr);
	return (0);
}