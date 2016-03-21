#include <Rtv1.h>

/* Subtract two vectors and return the resulting vector */
t_pos *vectorSub(t_pos *v1, t_pos *v2)
{
    t_pos *result;
    result = malloc(sizeof(t_pos));
    result->x = v1->x - v2->x;
    result->y = v1->y - v2->y;
    result->z = v1->z - v2->z;
    return (result);
}

/* Multiply two vectors and return the resulting scalar (dot product) */
double vectorDot(t_pos *v1, t_pos *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate Vector x Scalar and return resulting Vector*/
t_pos *vectorScale(double c, t_pos *v)
{
    t_pos *result;
    
    result = malloc(sizeof(t_pos));
    result->x = v->x * c;
    result->y = v->y * c;
    result->z = v->z * c;
    return (result);
}

/* Add two vectors and return the resulting vector */
t_pos *vectorAdd(t_pos *v1, t_pos *v2)
{
    t_pos *result;
    
    result = malloc(sizeof(t_pos));
    result->x = v1->x + v2->x;
    result->y = v1->y + v2->y;
    result->z = v1->z + v2->z;
    return (result);
}