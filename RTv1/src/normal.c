#include <Rtv1.h>

// REVOIR LES FONCTIONS DE NORMALE

t_ray *get_normal(t_object *object, t_ray *ray)
{
    t_ray *impact;
    
    impact = malloc(sizeof(t_ray));
    impact->O = vectorAdd(ray->O, vectorScale(object->dist, ray->D));
    if (object->type == SPHERE)
        impact->D = vectorSub(impact->O , object->O);
    else if (object->type == PLAN)
        impact->D = vectorCopy(object->D);
    else if (object->type == CONE)
    {
        float k;
        
        k = pow(object->rad / object->h, 2);
        impact->D = malloc(sizeof(t_pos));
        impact->D->x = impact->O->x - object->O->x;
       impact->D->y = k * object->O->y - k *impact->O->y;
       impact->D->z = impact->O->z - object->O->z;
    }
    else if (object->type == CYL)
    {
        impact->D = malloc(sizeof(t_pos));
        impact->D->x = 2 * (impact->O->x - object->O->x) - (2 * object->D->x * (object->D->x * (impact->O->x - object->O->x) + object->D->z * (impact->O->z - object->O->z) + object->D->y * (impact->O->y - object->O->y))) / (pow(object->D->z, 2) + pow(object->D->y, 2) + pow(object->D->x, 2));
        impact->D->y = 2 * (impact->O->y - object->O->y) - (2 * object->D->y * (object->D->x * (impact->O->x - object->O->x) + object->D->z * (impact->O->z - object->O->z) + object->D->y * (impact->O->y - object->O->y))) / (pow(object->D->z, 2) + pow(object->D->y, 2) + pow(object->D->x, 2));
        impact->D->z = 2 * (impact->O->z - object->O->z) - (2 * object->D->z * (object->D->x * (impact->O->x - object->O->x) + object->D->z * (impact->O->z - object->O->z) + object->D->y * (impact->O->y - object->O->y))) / (pow(object->D->z, 2) + pow(object->D->y, 2) + pow(object->D->x, 2));
    }
    vectorNorm(impact->D);
    return (impact);
}
