#include <Rtv1.h>

void	pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
    t->image->data[x * t->image->bpp / 8 + y * t->image->size_line] = (unsigned char)color->b;
    t->image->data[x * t->image->bpp / 8 + 1 + y * t->image->size_line] = (unsigned char)color->g;
    t->image->data[x * t->image->bpp / 8 + 2 + y * t->image->size_line] = (unsigned char)color->r;
}

t_ray   *get_ray(t_tool *t, double x, double y)
{
    t_ray   *ray;
    t_pos   *B;
    
    ray = malloc(sizeof(t_ray));
    ray->O = malloc(sizeof(t_pos));
    B  = malloc(sizeof(t_pos));
    ray->O->x = t->cam->pos->x;
    ray->O->y = t->cam->pos->y;
    ray->O->z = t->cam->pos->z;
    
    B->x = t->cam->upleft->x + t->cam->r_vect->x * t->cam->indent * x - t->cam->h_vect->x * t->cam->indent * y;
    B->y = t->cam->upleft->y + t->cam->r_vect->y * t->cam->indent * x - t->cam->h_vect->y * t->cam->indent * y;
    B->z = t->cam->upleft->z + t->cam->r_vect->z * t->cam->indent * x - t->cam->h_vect->z * t->cam->indent * y;
    
    ray->D = vectorSub(B, ray->O);
    vectorNorm(ray->D);
    return (ray);
}

void    draw(t_tool *t, double x, double y)
{
	t_ray *ray;
    double x0;
    double y0;
    t_color *final_color;
    t_color *curColor;
    
    final_color = new_color();
    x0 = x;
    while(x0 <= x + 0.5)
    {
        y0 = y;
        while (y0 <= y + 0.5)
        {
            ray = get_ray(t, x0, y0);
            curColor = get_color(ray, t);
            add_color(final_color, curColor);
            y0+= 0.5;
        }
        x0+= 0.5;
    }
    div_color(final_color, 4);
    normalize_color(final_color);
    pixel_put_to_image(t, x, y, final_color);
}

t_color    *get_color(t_ray *ray ,t_tool *t)
{
    t_object *curObject;
    t_color *final_color;
    t_ray   *impact;
    
    final_color = new_color();
    
    if ((curObject = intersection(t->l_objects, ray)))
    {
        init_color(t, curObject->color, final_color);
        impact = get_normal(curObject, ray);
        illuminate(t, curObject, impact, final_color);
    }
    return (final_color);
}
