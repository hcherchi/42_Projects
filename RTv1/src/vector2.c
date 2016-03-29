#include <rtv1.h>

//t_pos   *rotation(t_pos *vect, t_pos *axe)
//{
//    
//}

t_pos	*vectornew(double x, double y, double z)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_pos	*vectorcopy(t_pos *v1)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x;
	result->y = v1->y;
	result->z = v1->z;
	return (result);
}

void	vectornorm(t_pos *v)
{
	double	tmp;

	tmp = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * tmp;
	v->y = v->y * tmp;
	v->z = v->z * tmp;
}
