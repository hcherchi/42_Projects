#include <RTv1.h>
#include <stdio.h>
t_object    *intersection(t_object *l_objects, t_ray ray)
{
    float min;
    t_object *tmp;
    
    tmp = l_objects;
    min = 20000;
    
    while (tmp != NULL)
    {
        if (tmp->type == SPHERE)
            tmp->dist = intersection_sphere(tmp, ray, &min);
        else if (tmp->type == CONE)
            tmp->dist = intersection_cone(tmp, ray, &min);
        else if (tmp->type == PLAN)
            tmp->dist = intersection_plan(tmp, ray, &min);
        else if (tmp->type == CYL)
            tmp->dist = intersection_cyl(tmp, ray, &min);
        tmp = tmp->next;
    }
    if (min == 20000)
        return (NULL);
    while (l_objects != NULL)
    {
        if (l_objects->dist == min)
            return (l_objects);
        l_objects = l_objects->next;
    }
    return (NULL);
}

float     intersection_plan(t_object *plan, t_ray ray, float *min)
{
    float a;
    float b;
    
    a = plan->a * ray.D.x + plan->b * ray.D.y + plan->c * ray.D.z;
    b = plan->a * ray.O.x + plan->b * ray.O.y + plan->c * ray.O.z + plan->d;
    if (-b / a > 0)
    {
        if (-b / a < *min)
            *min = -b /  a;
        return (-b / a);
    }
    return 0;
}

float     intersection_sphere(t_object *sphere, t_ray ray,  float *min)
{
    float   a;
    float   b;
    float   c;
    t_pos   dist;
    float   discr;
    
    // resolution d'une equation du second degre
    a = vectorDot(&ray.D, &ray.D);
    dist = vectorSub(&ray.O, &sphere->O);
    b = 2 * vectorDot(&ray.D, &dist);
    c = vectorDot(&dist, &dist) - (sphere->rad * sphere->rad);
    discr = b * b - 4 * a * c;
    
    // pas de solution donc pas d'intersection
    if (discr < 0)
        return 0;
    
    // calcul des solution
    float sqrtdiscr = sqrtf(discr);
    float t0 = (-b + sqrtdiscr)/(2);
    float t1 = (-b - sqrtdiscr)/(2);
    
    // choisi la solution la plus proche
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0; //coef prends cette valeur. il represente la distance entre la camera et le point d'impact.
    return (t0);
}

float     intersection_cone(t_object *cone, t_ray ray, float *min)
{
    float   a;
    float   b;
    float   c;
    float   k;
    float   discr;
    
    k = pow(cone->rad / cone->h, 2);
    a = pow(ray.D.x, 2) + pow(ray.D.z, 2) - pow(ray.D.y, 2) * k;
    b = 2 * (ray.D.x * (ray.O.x - cone->O.x) + ray.D.z * (ray.O.z - cone->O.z) - ray.D.y * (ray.O.y - cone->O.y) * k);
    c = pow((ray.O.x - cone->O.x), 2) + pow((ray.O.z - cone->O.z), 2) - pow((ray.O.y - cone->O.y), 2) * k;
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return 0;
    float sqrtdiscr = sqrtf(discr);
    float t0 = (-b + sqrtdiscr)/(2);
    float t1 = (-b - sqrtdiscr)/(2);
    ft_putchar('\n');
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0;
    return t0;
}

float     intersection_cyl(t_object *cyl, t_ray ray, float *min)
{
    float   a;
    float   b;
    float   c;
    float   discr;
    float   k;
    
    k = pow(cyl->D.x, 2) + pow(cyl->D.y, 2) + pow(cyl->D.z, 2);
    a = vectorDot(&ray.D, &ray.D);
    b = 2 * (ray.D.x * (ray.O.x - cyl->O.x) + (ray.D.y) * (ray.O.y - cyl->O.y) + ray.D.z * (ray.O.z - cyl->O.z));
    c =  (ray.O.x - cyl->O.x) * (ray.O.x - cyl->O.x) + (ray.O.y - cyl->O.y) * (ray.O.y - cyl->O.y) + (ray.O.z - cyl->O.z) * (ray.O.z - cyl->O.z) - (cyl->rad * cyl->rad);
    a -= (pow(cyl->D.x * ray.D.x + cyl->D.y * ray.D.y + cyl->D.z * ray.D.z, 2) / k);
    b -= (2 * (cyl->D.x * ray.D.x + cyl->D.y * ray.D.y + cyl->D.z * ray.D.z) * (cyl->D.x * (ray.O.x - cyl->O.x) + cyl->D.y * (ray.O.y - cyl->O.y) + cyl->D.z * (ray.O.z - cyl->O.z)) / k);
    c -= (pow(cyl->D.x * (ray.O.x - cyl->O.x) + cyl->D.y * (ray.O.y - cyl->O.y) + cyl->D.z * (ray.O.z - cyl->O.z), 2) / k);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return 0;
    float sqrtdiscr = sqrtf(discr);
    float t0 = (-b + sqrtdiscr)/(2);
    float t1 = (-b - sqrtdiscr)/(2);
    //printf("%f - %f\n", t0, t1);
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0;
    printf("%f\n", t0);
    return t0;
}
