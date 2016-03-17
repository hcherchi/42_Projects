#include <RTv1.h>
#include <stdio.h>

t_pos rotation(t_pos axe, t_pos vect)
{
	t_pos rota_matrice;

	rota_matrice.x = - vect.x + 2 * vect.x * pow(axe.x, 2) + 2 * vect.y * axe.x * axe.y + 2 * vect.z * axe.x * axe.z;
	rota_matrice.y = - vect.y + 2 * vect.x * axe.x * axe.y + 2 * vect.y * pow(axe.y, 2) + vect.z * 2 * axe.y * axe.z;
	rota_matrice.z = - vect.z + 2 * vect.x * axe.x * axe.z + 2 * vect.y * axe.y * axe.z + 2 * vect.z * pow(axe.z, 2);
	vectorNorm(&rota_matrice);
	return(rota_matrice);
}
t_object    *intersection(t_object *l_objects, t_ray ray)
{
    double min;
    t_object *tmp;
    
    tmp = l_objects;
    min = 200000;
    
    
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
    if (min == 200000)
        return (NULL);
    tmp = l_objects;
    while (tmp != NULL)
    {
        if (tmp->dist == min)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

double     intersection_plan(t_object *plan, t_ray ray, double *min)
{
    double a;
    double b;
    
    a = plan->a * ray.D.x + plan->b * ray.D.y + plan->c * ray.D.z;
    b = plan->a * ray.O.x + plan->b * ray.O.y + plan->c *
    ray.O.z + plan->d;
    if (-b / a > E)
    {
        if (-b / a < *min)
            *min = -b /  a;
        return (-b / a);
    }
    return 0;
}

double     intersection_sphere(t_object *sphere, t_ray ray,  double *min)
{
    double   a;
    double   b;
    double   c;
    t_pos   dist;
    double   discr;
    
    // resolution d'une equation du second degre
    a = vectorDot(&ray.D, &ray.D);
    dist = vectorSub(&ray.O, &sphere->O);
    b = 2 * vectorDot(&ray.D, &dist);
    c = vectorDot(&dist, &dist) - (sphere->rad * sphere->rad);
    discr = b * b - 4 * a * c;
    
    // pas de solution donc pas d'intersection
    if (discr < E)
    {
        return 0;
    }
    // calcul des solution
    double sqrtdiscr = sqrtf(discr);
    double t0 = (-b + sqrtdiscr)/(2);
    double t1 = (-b - sqrtdiscr)/(2);
    
    // choisi la solution la plus proche
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0; //coef prends cette valeur. il represente la distance entre la camera et le point d'impact.
    return (t0);
}

double     intersection_cone(t_object *cone, t_ray ray, double *min)
{
    double   a;
    double   b;
    double   c;
    double   k;
    double   discr;
    
    k = pow(cone->rad / cone->h, 2);
    a = pow(ray.D.x, 2) + pow(ray.D.z, 2) - pow(ray.D.y, 2) * k;
    b = 2 * (ray.D.x * (ray.O.x - cone->O.x) + ray.D.z * (ray.O.z - cone->O.z) - ray.D.y * (ray.O.y - cone->O.y) * k);
    c = pow((ray.O.x - cone->O.x), 2) + pow((ray.O.z - cone->O.z), 2) - pow((ray.O.y - cone->O.y), 2) * k;
    discr = b * b - 4 * a * c;
    if (discr < E)
        return 0;
    double sqrtdiscr = sqrtf(discr);
    double t0 = (-b + sqrtdiscr)/(2);
    double t1 = (-b - sqrtdiscr)/(2);
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0;
    return t0;
}

double     intersection_cyl(t_object *cyl, t_ray ray, double *min)
{
    double   a;
    double   b;
    double   c;
    double   discr;
    double   k;
    
    k = pow(cyl->D.x, 2) + pow(cyl->D.y, 2) + pow(cyl->D.z, 2);
    a = vectorDot(&ray.D, &ray.D);
    b = 2 * (ray.D.x * (ray.O.x - cyl->O.x) + (ray.D.y) * (ray.O.y - cyl->O.y) + ray.D.z * (ray.O.z - cyl->O.z));
    c =  (ray.O.x - cyl->O.x) * (ray.O.x - cyl->O.x) + (ray.O.y - cyl->O.y) * (ray.O.y - cyl->O.y) + (ray.O.z - cyl->O.z) * (ray.O.z - cyl->O.z) - (cyl->rad * cyl->rad);
    a -= (pow(cyl->D.x * ray.D.x + cyl->D.y * ray.D.y + cyl->D.z * ray.D.z, 2) / k);
    b -= (2 * (cyl->D.x * ray.D.x + cyl->D.y * ray.D.y + cyl->D.z * ray.D.z) * (cyl->D.x * (ray.O.x - cyl->O.x) + cyl->D.y * (ray.O.y - cyl->O.y) + cyl->D.z * (ray.O.z - cyl->O.z)) / k);
    c -= (pow(cyl->D.x * (ray.O.x - cyl->O.x) + cyl->D.y * (ray.O.y - cyl->O.y) + cyl->D.z * (ray.O.z - cyl->O.z), 2) / k);
    discr = b * b - 4 * a * c;
    if (discr < E)
        return 0;
    double sqrtdiscr = sqrtf(discr);
    double t0 = (-b + sqrtdiscr)/(2);
    double t1 = (-b - sqrtdiscr)/(2);
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 < 0)
        return 0;
    else if (t0 < *min)
        *min = t0;
    return t0;
}
