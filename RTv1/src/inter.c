#include <Rtv1.h>

t_pos *rotation(t_pos *axe, t_pos *vect)
{
	t_pos *rota_matrice;

	rota_matrice = malloc(sizeof(t_pos));
	rota_matrice->x = - vect->x + 2 * vect->x * pow(axe->x, 2) + 2 * vect->y * axe->x * axe->y + 2 * vect->z * axe->x * axe->z;
	rota_matrice->y = - vect->y + 2 * vect->x * axe->x * axe->y + 2 * vect->y * pow(axe->y, 2) + vect->z * 2 * axe->y * axe->z;
	rota_matrice->z = - vect->z + 2 * vect->x * axe->x * axe->z + 2 * vect->y * axe->y * axe->z + 2 * vect->z * pow(axe->z, 2);
	vectorNorm(rota_matrice);
	return(rota_matrice);
}

float   minimum(t_object *l_objects)
{
    float min;
    
    min = 200000;
    while (l_objects != NULL)
    {
        if (l_objects->dist != -1 && l_objects->dist < min)
            min = l_objects->dist;
        l_objects = l_objects->next;
    }
    return (min);
}

t_object   *intersection(t_object *l_objects, t_ray *ray)
{
	t_object *tmp;
    float min;
 
	tmp = l_objects;
	while (tmp != NULL)
	{
		if (tmp->type == SPHERE)
			tmp->dist = intersection_sphere(tmp, ray);
		else if (tmp->type == CONE)
			tmp->dist = intersection_cone(tmp, ray);
		else if (tmp->type == PLAN)
			tmp->dist = intersection_plan(tmp, ray);
		else if (tmp->type == CYL)
			tmp->dist = intersection_cyl(tmp, ray);
		tmp = tmp->next;
	}
    tmp = l_objects;
    min = minimum(tmp);
    if (min == 200000)
        return (NULL);
	while (tmp != NULL)
	{
		if (tmp->dist == min)
			return (tmp);
		tmp = tmp->next;
	}
    ft_putendl("PROBLEM");
    exit(0);
	return (NULL);
}

float     intersection_plan(t_object *plan, t_ray *ray)
{
	float a;
	float b;

	a = plan->D->x * ray->D->x + plan->D->y * ray->D->y + plan->D->z * ray->D->z;
	b = plan->D->x * ray->O->x + plan->D->y * ray->O->y + plan->D->z * ray->O->z + plan->h;
	if (-b / a > E)
		return (-b / a);
	return -1;
}

float     intersection_sphere(t_object *sphere, t_ray *ray)
{
	t_equation  param;
	t_pos   *dist;

	dist = vectorSub(ray->O, sphere->O);
	param.a = vectorDot(ray->D, ray->D);
	param.b = 2 * vectorDot(ray->D, dist);
	param.c = vectorDot(dist, dist) - (sphere->rad * sphere->rad);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return -1;
	param.t0 = (-param.b + sqrtf(param.discr))/(2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr))/(2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return -1;
	return (param.t0);
}

float     intersection_cone(t_object *cone, t_ray *ray)
{
	float   k;
	t_equation param;

	k = pow(cone->rad / cone->h, 2);
	param.a = pow(ray->D->x, 2) + pow(ray->D->z, 2) - pow(ray->D->y, 2) * k;
	param.b = 2 * (ray->D->x * (ray->O->x - cone->O->x) + ray->D->z * (ray->O->z - cone->O->z) - ray->D->y * (ray->O->y - cone->O->y) * k);
	param.c = pow((ray->O->x - cone->O->x), 2) + pow((ray->O->z - cone->O->z), 2) - pow((ray->O->y - cone->O->y), 2) * k;
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return -1;
	param.t0 = (-param.b + sqrtf(param.discr))/(2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr))/(2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return -1;
	return param.t0;
}
float     intersection_cyl(t_object *cyl, t_ray *ray)
{
	t_equation param;
	float   k;

	k = pow(cyl->D->x, 2) + pow(cyl->D->y, 2) + pow(cyl->D->z, 2);
	param.a = vectorDot(ray->D, ray->D) - (pow(cyl->D->x * ray->D->x + cyl->D->y * ray->D->y + cyl->D->z * ray->D->z, 2) / k);
	param.b = 2 * (ray->D->x * (ray->O->x - cyl->O->x) + (ray->D->y) * (ray->O->y - cyl->O->y) + ray->D->z * (ray->O->z - cyl->O->z)) - (2 * (cyl->D->x * ray->D->x + cyl->D->y * ray->D->y + cyl->D->z * ray->D->z) * (cyl->D->x * (ray->O->x - cyl->O->x) + cyl->D->y * (ray->O->y - cyl->O->y) + cyl->D->z * (ray->O->z - cyl->O->z)) / k);
	param.c =  (ray->O->x - cyl->O->x) * (ray->O->x - cyl->O->x) + (ray->O->y - cyl->O->y) * (ray->O->y - cyl->O->y) + (ray->O->z - cyl->O->z) * (ray->O->z - cyl->O->z) - (cyl->rad * cyl->rad) - (pow(cyl->D->x * (ray->O->x - cyl->O->x) + cyl->D->y * (ray->O->y - cyl->O->y) + cyl->D->z * (ray->O->z - cyl->O->z), 2) / k);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return -1;
	param.t0 = (-param.b + sqrtf(param.discr))/(2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr))/(2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return -1;
	return param.t0;
}
