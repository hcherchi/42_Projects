#include <RTv1.h>
#include <stdio.h>

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
    // position de depart du rayon (camera)
    ray->O->x = t->cam->pos->x;
    ray->O->y = t->cam->pos->y;
    ray->O->z = t->cam->pos->z;
    
    // calcul de la position d'arrivee du rayon sur le viewplane
    B->x = t->cam->upleft->x + t->cam->r_vect->x * t->cam->indent * x - t->cam->h_vect->x * t->cam->indent * y;
    B->y = t->cam->upleft->y + t->cam->r_vect->y * t->cam->indent * x - t->cam->h_vect->y * t->cam->indent * y;
    B->z = t->cam->upleft->z + t->cam->r_vect->z * t->cam->indent * x - t->cam->h_vect->z * t->cam->indent * y;
    
    // calcul du vecteur directeur du rayon
    ray->D = vectorSub(B, ray->O);
    vectorNorm(ray->D); // norme pour avoir taille de vecteur = 1 (vecteur unitaire)
    return (ray);
}

void    draw(t_tool *t, double x, double y)
{
	t_ray *ray;
    double x0;
    double y0;
    t_color *final_color;
    
    final_color = new_color();
    x0 = x;
    while(x0 <= x + 0.5)
    {
        y0 = y;
        while (y0 <= y + 0.5)
        {
            ray = get_ray(t, x0, y0);
            add_color(final_color, draw_suite(ray, t));
            y0+= 0.5;
        }
        x0+= 0.5;
    }
    div_color(final_color, 4);
    normalize_color(final_color);
    pixel_put_to_image(t, x, y, final_color);
}

t_color    *draw_suite(t_ray *ray ,t_tool *t)
{
    t_object *curObject;
    t_object *curObject2;
    t_color *final_color;
    t_ray   *lightray;
    t_ray   *impact;
    t_light *curLight;

    t_pos   *reflectray;
    t_pos   *invlight;
    double kdiff;
    double kspec;
    
    
    final_color = malloc(sizeof(t_color));
    final_color = new_color();
    lightray = malloc(sizeof(t_ray));
    impact = malloc(sizeof(t_ray));
    
    if ((curObject = intersection(t->l_objects, ray)))
    {
        impact->O = vectorAdd(ray->O, vectorScale(curObject->dist, ray->D));
        find_normal(impact, curObject);
        vectorNorm(impact->D);
        
        init_color(t, curObject->color, final_color);
        curLight = t->l_lights;
        while (curLight)
        {
            lightray->O = vectorCopy(curLight->O);
            lightray->D = vectorSub(impact->O, lightray->O);
            vectorNorm(lightray->D);
    
            if ((curObject2 = intersection(t->l_objects, lightray)) && curObject2 == curObject)
            {
                invlight = vectorScale(-1, lightray->D);
                kdiff = vectorDot(invlight, impact->D) * MAX((curLight->dist - curObject->dist) / curLight->dist, 0);
                if (kdiff >= 0)
                {
                    update_color(kdiff * 1, curLight->color, final_color, curObject->color);
                    reflectray = rotation(impact->D, invlight);
                    vectorNorm(reflectray);
                    kspec = vectorDot(invlight, reflectray);
                    if (kspec >= 0)
                        update_color(pow(kspec, 20) * MAX((curLight->dist - curObject->dist) / curLight->dist, 0) * curObject->shiny , curLight->color, final_color, curObject->color);
                }
            }
            curLight = curLight->next;
        }
    }
    return (final_color);
}
