
#ifndef RTv1_H
# define RTv1_H
# include "mlx.h"
# include <math.h>
# include "libft.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define SPHERE 0
#define CYL 1
#define CONE 2
#define PLAN 3
#define E -0.000001

typedef struct s_color
{
    double       r;
    double       g;
    double       b;
}               t_color;

typedef struct  s_pos
{
    double       x;
    double       y;
    double       z;
}               t_pos;

typedef struct s_object
{
    int         type;
    double       dist;
    t_color     color;
    t_pos       O;
    t_pos       D;
    double               rad;
    double               h;
    double               a;
    double               b;
    double               c;
    double               d;
    struct s_object     *next;
    int                 mirror;
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
    double      dist;
    struct s_light     *next;
}              t_light;

typedef struct  s_cam
{
    t_pos       pos;
    t_pos       h_vect;
    t_pos       r_vect;
    t_pos       vect;
    double       dist;
    double       W;
    double       H;
    t_pos       upleft;
    double       x_res;
    double       y_res;
    double       x_indent;
    double       y_indent;
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
    double       LumAmb;
}				t_tool;

t_object    *intersection(t_object *l_objects, t_ray ray);
double     intersection_plan(t_object *plan, t_ray ray, double *coef);
double     intersection_sphere(t_object *sphere, t_ray ray, double *coef);
double     intersection_cone(t_object *cone, t_ray ray, double *coef);
double     intersection_cyl(t_object *cyl, t_ray ray, double *coef);


void	pixel_put_to_image(t_tool *t, int x, int y, t_color color);
t_color    draw_suite(t_light *l_lights, t_ray ray, t_object *l_objects, t_tool *t);
t_ray  get_ray(t_tool *t, double x, double y);
void    draw(t_tool *t, double x, double y);

void    find_normal(t_ray *impact, t_object *object);

void vectorNorm(t_pos *v);
t_pos vectorMul(t_pos *v1, t_pos *v2);
t_pos vectorSub(t_pos *v1, t_pos *v2);
double vectorDot(t_pos *v1, t_pos *v2);
t_pos vectorScale(double c, t_pos *v);
t_pos vectorAdd(t_pos *v1, t_pos *v2);
t_pos vectorCopy(t_pos *v1);
t_pos rotation(t_pos axe, t_pos vect);
#endif
