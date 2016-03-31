#include <rtv1.h>
#include <stdio.h>

t_color     *get_sky_color(t_ray *ray, t_tool *t)
{
    t_pos *impact;
    double      x;
    double      y;
    
    impact = malloc(sizeof(t_pos));
    impact = vectoradd(ray->o, vectorscale(100, ray->d));
    vectornorm(impact);
    x = (0.5 + (atan2(impact->z, impact->x) / (2 * M_PI))) * t->sky->width;
    y = (0.5 - asin(impact->y) / M_PI) * t->sky->height;
    free(impact);
    return (extract_color(t, t->sky, x, y));
}

t_color     *get_flash(t_ray *ray, t_tool *t)
{
    t_light     *light;
    t_color     *flash;
    t_pos       *flashray;
    double      angle;
    
    flash = new_color();
    light = t->l_lights;
    while (light)
    {
        if (light->type == SUN)
        {
            flashray = vectorsub(light->o, ray->o);
            vectornorm(flashray);
            angle = vectordot(flashray, ray->d);
            if (angle > 0)
                flash = add_color(flash, mult_color(light->color, pow(angle, 10)));
        }
        light = light->next;
    }
    return (flash);
}