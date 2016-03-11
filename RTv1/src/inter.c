#include <RTv1.h>

int     intersection_plan(t_plan plan, t_ray ray, float *coef)
{
    float a;
    float b;
    
    a = plan.a * ray.D.x + plan.b * ray.D.y + plan.c * ray.D.z;
    b = plan.a * ray.O.x + plan.b * ray.O.y + plan.c * ray.O.z + plan.d;
    if (-b / a < 0)
    {
        *coef = -b / a;
        return 1;
    }
    return 0;
}

int     intersection_sphere(t_sphere sphere, t_ray ray, float *coef)
{
    float   a;
    float   b;
    float   c;
    t_pos   dist;
    float   discr;
    
    a = vectorDot(&ray.D, &ray.D);
    dist = vectorSub(&ray.O, &sphere.O);
    b = 2 * vectorDot(&ray.D, &dist);
    c = vectorDot(&dist, &dist) - (sphere.rad * sphere.rad);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return 0;
//    float sqrtdiscr = sqrtf(discr);
//    float t0 = (-b + sqrtdiscr)/(2);
//    float t1 = (-b - sqrtdiscr)/(2);
//    if (fabs(t0) > fabs(t1))
//        t0 = t1;
//    if (t0 > 0)
//        return 0;
//    else
        *coef = 0;
    return 1;
}

int     intersection_cone(t_cone cone, t_ray ray, float *coef)
{
    float   a;
    float   b;
    float   c;
    float   k;
    float   discr;
    
    k = pow(cone.rad / cone.h, 2);
    a = pow(ray.D.x, 2) + pow(ray.D.z, 2) - pow(ray.D.y, 2) * k;
    b = 2 * (ray.D.x * (ray.O.x - cone.O.x) + ray.D.z * (ray.O.z - cone.O.z) - ray.D.y * (ray.O.y - cone.O.y) * k);
    c = pow((ray.O.x - cone.O.x), 2) + pow((ray.O.z - cone.O.z), 2) - pow((ray.O.y - cone.O.y), 2) * k;
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return 0;
    float sqrtdiscr = sqrtf(discr);
    float t0 = (-b + sqrtdiscr)/(2);
    float t1 = (-b - sqrtdiscr)/(2);
    ft_putchar('\n');
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 > 0)
        return 0;
    else
        *coef = t0;
    return 1;
}

int     intersection_cyl(t_cyl cyl, t_ray ray, float *coef)
{
    float   a;
    float   b;
    float   c;
    float   discr;
    float   k;
    
    k = pow(cyl.vect.D.x, 2) + pow(cyl.vect.D.y, 2) + pow(cyl.vect.D.z, 2);
    a = vectorDot(&ray.D, &ray.D);
    b = 2 * (ray.D.x * (ray.O.x - cyl.vect.O.x) + (ray.D.y) * (ray.O.y - cyl.vect.O.y) + ray.D.z * (ray.O.z - cyl.vect.O.z));
    c =  (ray.O.x - cyl.vect.O.x) * (ray.O.x - cyl.vect.O.x) + (ray.O.y - cyl.vect.O.y) * (ray.O.y - cyl.vect.O.y) + (ray.O.z - cyl.vect.O.z) * (ray.O.z - cyl.vect.O.z) - (cyl.rad * cyl.rad);
    a -= (pow(cyl.vect.D.x * ray.D.x + cyl.vect.D.y * ray.D.y + cyl.vect.D.z * ray.D.z, 2) / k);
    b -= (2 * (cyl.vect.D.x * ray.D.x + cyl.vect.D.y * ray.D.y + cyl.vect.D.z * ray.D.z) * (cyl.vect.D.x * (ray.O.x - cyl.vect.O.x) + cyl.vect.D.y * (ray.O.y - cyl.vect.O.y) + cyl.vect.D.z * (ray.O.z - cyl.vect.O.z)) / k);
    c -= (pow(cyl.vect.D.x * (ray.O.x - cyl.vect.O.x) + cyl.vect.D.y * (ray.O.y - cyl.vect.O.y) + cyl.vect.D.z * (ray.O.z - cyl.vect.O.z), 2) / k);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return 0;
    float sqrtdiscr = sqrtf(discr);
    float t0 = (-b + sqrtdiscr)/(2);
    float t1 = (-b - sqrtdiscr)/(2);
    //printf("%f - %f\n", t0, t1);
    if (fabs(t0) > fabs(t1))
        t0 = t1;
    if (t0 > 0)
        return 0;
    else
        *coef = t0;
    return 1;
}
