#include <RTv1.h>

void    find_normal(t_ray *impact, t_object *object)
{
    float k;
    
    if (object->type == SPHERE)
    {
        impact->D = vectorSub(&impact->O, &object->O);
    }
    else if (object->type == PLAN)
    {
        impact->D.x = object->a;
        impact->D.y = object->b;
        impact->D.z = object->c;
    }
    else if (object->type == CONE)
    {
        k = pow(object->rad / object->h, 2);
        impact->D.x = impact->O.x - object->O.x;
        impact->D.y = -2 * impact->O.y * k + 2 * k * object->O.y;
        impact->D.z = impact->O.z - object->O.z;
    }
    else if (object->type == CYL)
    {
        impact->D.x = impact->O.x - object->O.x;
        impact->D.y = 0;
        impact->D.z = impact->O.z - object->O.z;
    }
}