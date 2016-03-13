
#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include "libft.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define SPHERE 0
#define CYL 1
#define CONE 2
#define PLAN 3

typedef struct s_color
{
    float       r;
    float       g;
    float       b;
}               t_color;

typedef struct  s_pos
{
    float       x;
    float       y;
    float       z;
}               t_pos;

typedef struct s_object
{
    int         type;
    float       dist;
    t_color     color;
    t_pos       O;
    t_pos       D;
    float               rad;
    float               h;
    float               a;
    float               b;
    float               c;
    float               d;
    struct s_object     *next;
}               t_object;

typedef struct  s_ray
{
    t_pos       O;
    t_pos       D;
}               t_ray;

typedef struct s_light
{
    t_pos       O;
    t_color     color;
}              t_light;

typedef struct  s_cam
{
    t_pos       pos;
    t_pos       h_vect;
    t_pos       r_vect;
    t_pos       vect;
    float       dist;
    float       W;
    float       H;
    t_pos       upleft;
    float       x_res;
    float       y_res;
    float       x_indent;
    float       y_indent;
}               t_cam;

typedef struct  s_image
{
    int         endian;
    int         size_line;
    int         bpp;
    char        *data;
}               t_image;

typedef struct	s_tool
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
    t_image     image;
    t_cam       cam;
    float       LumAmb;
}				t_tool;

t_object    *intersection(t_object *l_objects, t_ray ray);
float     intersection_plan(t_object *plan, t_ray ray, float *coef);
float     intersection_sphere(t_object *sphere, t_ray ray, float *coef);
float     intersection_cone(t_object *cone, t_ray ray, float *coef);
float     intersection_cyl(t_object *cyl, t_ray ray, float *coef);


void	pixel_put_to_image(t_tool *t, int x, int y, t_color color);
t_ray  get_ray(t_tool *t, float x, float y);
void    draw(t_tool *t, float x, float y);

void    find_normal(t_ray *impact, t_object *object);

void vectorNorm(t_pos *v);
t_pos vectorMul(t_pos *v1, t_pos *v2);
t_pos vectorSub(t_pos *v1, t_pos *v2);
float vectorDot(t_pos *v1, t_pos *v2);
t_pos vectorScale(float c, t_pos *v);
t_pos vectorAdd(t_pos *v1, t_pos *v2);

#endif
