#include <RTv1.h>
#include <stdio.h>

void init_color(t_tool *t, t_color objcolor, t_color *final_color)
{
    final_color->r = objcolor.r * t->LumAmb;
    final_color->g = objcolor.g * t->LumAmb;
    final_color->b = objcolor.b * t->LumAmb;
}

void update_color(double k, t_color lightcolor, t_color *final_color, t_color objcolor)
{
    final_color->r += (lightcolor.r + objcolor.r) / 2 * k * 0.7;
    final_color->g += (lightcolor.g + objcolor.g) / 2 * k * 0.7;
    final_color->b += (lightcolor.b + objcolor.b) / 2 * k * 0.7;
}

void    normalize_color(t_color *final_color)
{
    if (final_color->r < 0)
        final_color->r = 0;
    if (final_color->b < 0)
        final_color->b = 0;
    if (final_color->g < 0)
        final_color->g = 0;
    if (final_color->r > 255)
        final_color->r = 255;
    if (final_color->b > 255)
        final_color->b = 255;
    if (final_color->g > 255)
        final_color->g = 255;
}

void	pixel_put_to_image(t_tool *t, int x, int y, t_color color)
{
    t->image.data = mlx_get_data_addr(t->mlx_img, &t->image.bpp, &t->image.size_line, &t->image.endian);
    t->image.data[x * t->image.bpp / 8 + y * t->image.size_line] = (unsigned char)color.b;
    t->image.data[x * t->image.bpp / 8 + 1 + y * t->image.size_line] = (unsigned char)color.g;
    t->image.data[x * t->image.bpp / 8 + 2 + y * t->image.size_line] = (unsigned char)color.r;
}

t_ray  get_ray(t_tool *t, double x, double y)
{
    t_ray  ray;
    t_pos   B;
    
    // position de depart du rayon (Camera)
    ray.O.x = t->cam.pos.x;
    ray.O.y = t->cam.pos.y;
    ray.O.z = t->cam.pos.z;
    
    // calcul de la position d'arrivee du rayon sur le viewplane
    B.x = t->cam.upleft.x + t->cam.r_vect.x * t->cam.x_indent * x - t->cam.h_vect.x * t->cam.y_indent * y;
    B.y = t->cam.upleft.y + t->cam.r_vect.y * t->cam.x_indent * x - t->cam.h_vect.y * t->cam.y_indent * y;
    B.z = t->cam.upleft.z + t->cam.r_vect.z * t->cam.x_indent * x - t->cam.h_vect.z * t->cam.y_indent * y;
    
    // calcul du vecteur directeur du rayon
    ray.D = vectorSub(&B, &ray.O);
    vectorNorm(&ray.D); // norme pour avoir taille de vecteur = 1 (vecteur unitaire)
    return (ray);
}


void    draw(t_tool *t, double x, double y)
{
    t_ray  ray;
    t_light *l_lights;
    t_light *light;
    t_light *light2;
    t_color final_color;
    t_object *l_objects;
    t_object *plan;
    t_object *plan2;
    t_object *sphere;
    t_object *sphere2;
    t_object *curObject;
    t_object *curObject2;
    
    double k;
    
    plan2 = malloc(sizeof(t_object));
    sphere = malloc(sizeof(t_object));
    sphere2 = malloc(sizeof(t_object));
    plan = malloc(sizeof(t_object)); 
    light = malloc(sizeof(t_light));
    light2 = malloc(sizeof(t_light));

    sphere->rad = 0.5;
    sphere->O.x = -0.4;
    sphere->O.y = -0.5;
    sphere->O.z = 4;
    sphere->color.r = 255;
    sphere->color.g = 0;
    sphere->color.b = 0;
    sphere->type = SPHERE;

    sphere2->rad = 0.5;
    sphere2->O.x =  -1;
    sphere2->O.y = -0.5;
    sphere2->O.z = 4;
    sphere2->color.r = 255;
    sphere2->color.g = 0;
    sphere2->color.b = 0;
    sphere2->type = SPHERE;
    
    plan2->a = 0;
    plan2->b = 0;
    plan2->c = -1;
    plan2->d = 10;
    plan2->color.r = 23;
    plan2->color.g = 255;
    plan2->color.b = 153;
    plan2->type = PLAN;

    
    plan->a = 0;
    plan->b = 1;
    plan->c = 0;
    plan->d = 1;
    plan->color.r = 153;
    plan->color.g = 255;
    plan->color.b = 153;
    plan->type = PLAN;
    
    l_objects = plan;
    plan->next = plan2;
    plan2->next = sphere;
    sphere->next = sphere2;
	sphere2->next = NULL;
    
    light->O.x = 3;
    light->O.y = 1;
    light->O.z = 7;
    light->color.r = 255;
    light->color.g = 255;
    light->color.b = 255;
    light->dist = 15;
    
    light2->O.x = -1;
    light2->O.y = 1;
    light2->O.z = 3;
    light2->color.r = 255;
    light2->color.g = 255;
    light2->color.b = 255;
    light2->dist = 15;
    
    l_lights = light;
    light->next = light2;
    light2->next = NULL;

    ray = get_ray(t, x, y);
    
		
    if ((curObject = intersection(l_objects, ray)))
    {
        t_ray   impact;
        init_color(t, curObject->color, &final_color);

        impact.O.x = ray.O.x + ray.D.x * curObject->dist;
        impact.O.y = ray.O.y + ray.D.y * curObject->dist;
        impact.O.z = ray.O.z + ray.D.z * curObject->dist;
        
        while (l_lights)
        {
            t_ray   lightray;
			t_pos	rayflexion;

            lightray.O.x = l_lights->O.x;
            lightray.O.y = l_lights->O.y;
            lightray.O.z = l_lights->O.z;
        
            lightray.D = vectorSub(&impact.O, &lightray.O);
            vectorNorm(&lightray.D);
			rayflexion = rotation(impact,lightray);
			rayflexion = vectorScale(-1, &rayflexion);
        
            if ((curObject2 = intersection(l_objects, lightray)) && curObject2 == curObject)
            {
                find_normal(&impact, curObject);
                vectorNorm(&impact.D);
                k = MAX(acos(vectorDot(&lightray.D, &impact.D)) - M_PI / 2, 0);
				k += pow(MAX(acos(vectorDot(&lightray.D, &rayflexion)), 0), 10);
                k *= MAX(0, (l_lights->dist - curObject->dist) / l_lights->dist);
                update_color(k, l_lights->color, &final_color, curObject->color);
            }
            l_lights = l_lights->next;
        }
        normalize_color(&final_color);
        pixel_put_to_image(t, x, y, final_color);
    }
}
