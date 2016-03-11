#include <RTv1.h>

/* Subtract two vectors and return the resulting vector */
t_pos vectorSub(t_pos *v1, t_pos *v2)
{
    t_pos result;
    result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    result.z = v1->z - v2->z;
    return (result);
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(t_pos *v1, t_pos *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate Vector x Scalar and return resulting Vector*/
t_pos vectorScale(float c, t_pos *v)
{
    t_pos result;
    result.x = v->x * c;
    result.y = v->y * c;
    result.z = v->z * c;
    return (result);
}

/* Add two vectors and return the resulting vector */
t_pos vectorAdd(t_pos *v1, t_pos *v2)
{
    t_pos result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;
    return (result);
}

void vectorNorm(t_pos *v)
{
    float tmp;
    tmp = 1/sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
    v->x = v->x * tmp;
    v->y = v->y * tmp;
    v->z = v->z * tmp;
}

t_pos vectorMul(t_pos *v1, t_pos *v2)
{
    t_pos v;
    v.x = v1->x * v2->x;
    v.y = v1->y * v2->y;
    v.z = v1->z * v2->z;
    return (v);
}