#include <Rtv1.h>

t_ray   *get_lightray(t_ray *impact, t_light *curLight)
{
    t_ray *lightray;
    
    lightray = malloc(sizeof(t_ray));
    lightray->O = vectorCopy(curLight->O);
    lightray->D = vectorSub(impact->O, lightray->O);
    vectorNorm(lightray->D);
    return (lightray);
}

double  get_kdiff(t_ray *lightray, t_ray *impact)
{
    double  kdiff;
    t_pos   *invlight;
    
    invlight = vectorScale(-1, lightray->D);
    kdiff = vectorDot(invlight, impact->D);
    return (kdiff);
}

double  get_kspec(t_ray *lightray, t_ray *impact)
{
    double kspec;
    t_pos   *invlight;
    t_pos *reflectray;
    
    invlight = vectorScale(-1, lightray->D);
    reflectray = rotation(impact->D, invlight);
    vectorNorm(reflectray);
    kspec = vectorDot(invlight, reflectray);
    return (kspec);
}

void    illuminate(t_tool *t, t_object *curObject, t_ray *impact, t_color *final_color)
{
    t_light *curLight;
    t_ray   *lightray;
    t_object *curObject2;
    t_k     k;
    
    curLight = t->l_lights;
    while (curLight)
    {
        lightray = get_lightray(impact, curLight);
        if ((curObject2 = intersection(t->l_objects, lightray)) && curObject2 == curObject)
        {
            k.dist = MAX((curLight->dist - curObject->dist) / curLight->dist, 0);
            k.diff = get_kdiff(lightray, impact);
            if (k.diff >= 0)
            {
                update_color(k.diff * k.dist, curLight->color, final_color, curObject->color);
                k.spec = get_kspec(lightray, impact);
                if (k.spec >= 0)
                    update_color(pow(k.spec, 20) * k.dist * curObject->shiny , curLight->color, final_color, curObject->color);
            }
        }
        curLight = curLight->next;
    }
}

void	update_color(double k, t_color *lightco, t_color *f_c, t_color *objcol)
{
    f_c->r += (lightco->r + 3 * objcol->r) / 4 * k;
    f_c->g += (lightco->g + 3 * objcol->g) / 4 * k;
    f_c->b += (lightco->b + 3 * objcol->b) / 4 * k;
}
