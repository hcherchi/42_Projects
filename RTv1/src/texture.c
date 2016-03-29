#include <rtv1.h>

t_color *    extract_color(t_tool *t, t_image *texture, int x, int y)
{
    t_color *c;
    int color;
    unsigned int lcolor;
    
    color = texture->data[x * texture->bpp / 8 + y * texture->size_line];
    color += texture->data[x * texture->bpp / 8 + 1 + y * texture->size_line] * 256;
    color += texture->data[x * texture->bpp / 8 + 2 + y * texture->size_line] * 256 * 256;
    lcolor = mlx_get_color_value(t->mlx_ptr, color);
    c = new_color();
    c->r = ((lcolor & 0xFF0000) >> 16);
    c->g = ((lcolor & 0xFF00) >> 8);
    c->b = ((lcolor & 0xFF));
    return (c);
}

t_color     *get_texture_color(t_object *object, t_ray *impact, t_tool *t)
{
    double x;
    double y;
    t_color *color;
    double  tmp;
    int     div;
    
    if (object->type == PLAN)
    {
        x = impact->o->x / 0.0008;
        y = -impact->o->z / 0.0008;
        
        tmp = y / object->texture->height;
        div = floor(tmp);
        y = (tmp - div) * object->texture->height;
        if (div % 2 != 0)
        {
            x += (object->texture->width / 2);
        }
        tmp = x / object->texture->width;
        div = floor(tmp);
        x = (tmp - div) * object->texture->height;
    }
    if (object->type == SPHERE)
    {
        x = (0.5 + (atan2(impact->d->z, impact->d->x) / (2 * M_PI))) * object->texture->width;
        y = (0.5 - asin(impact->d->y) / M_PI) * object->texture->height;
    }
    color = extract_color(t, object->texture, x, y);
    return (color);
}