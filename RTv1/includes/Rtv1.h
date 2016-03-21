#ifndef Rtv1_H
# define Rtv1_H
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include "libft.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define SPHERE 0
#define CYL 1
#define CONE 2
#define PLAN 3
#define E -0.000001

typedef struct s_k
{
    double      spec;
    double      diff;
    double      dist;
}               t_k;

typedef struct s_equation
{
	double      a;
	double      b;
	double      c;
	double      discr;
	double      t1;
	double      t0;
}               t_equation;

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
	t_color     *color;
	t_pos       *O;
	t_pos       *D;
	double               rad;
	double               h;
	double                shiny;
	int             mirror;
	struct s_object     *next;
}               t_object;

typedef struct  s_ray
{
	t_pos       *O;
	t_pos       *D;
}               t_ray;

typedef struct s_light
{
	t_pos       *O;
	t_color     *color;
	double      dist;
	struct s_light     *next;
}              t_light;

typedef struct  s_cam
{
	t_pos       *pos;
	t_pos       *h_vect;
	t_pos       *r_vect;
	t_pos       *vect;
	double       dist;
	double       W;
	double       H;
	t_pos       *upleft;
	double       x_res;
	double       y_res;
	double       indent;
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
	t_object    *l_objects;
	t_light     *l_lights;
	t_image     *image;
	t_cam       *cam;
	double       LumAmb;
}				t_tool;

// INTERSECTIONS
t_object    *intersection(t_object *l_objects, t_ray *ray);
double     intersection_plan(t_object *plan, t_ray *ray, double *coef);
double     intersection_sphere(t_object *sphere, t_ray *ray, double *coef);
double     intersection_cone(t_object *cone, t_ray *ray, double *coef);
double     intersection_cyl(t_object *cyl, t_ray *ray, double *coef);


// DESSIN
void    draw(t_tool *t, double x, double y);
t_ray  *get_ray(t_tool *t, double x, double y);
t_color   *get_color(t_ray *ray ,t_tool *t);
t_ray    *get_normal(t_object *object, t_ray *ray);
t_ray   *get_lightray(t_ray *impact, t_light *curLight);
void    illuminate(t_tool *t, t_object *curObject, t_ray *impact, t_color *final_color);
double  get_kspec(t_ray *lightray, t_ray *impact);
double  get_kdiff(t_ray *lightray, t_ray *impact);
void update_color(double k, t_color *lightcolor, t_color *final_color, t_color *objcolor);
void	pixel_put_to_image(t_tool *t, int x, int y, t_color *color);

// VECTOR
void vectorNorm(t_pos *v);
t_pos *vectorSub(t_pos *v1, t_pos *v2);
double vectorDot(t_pos *v1, t_pos *v2);
t_pos *vectorScale(double c, t_pos *v);
t_pos *vectorAdd(t_pos *v1, t_pos *v2);
t_pos *vectorCopy(t_pos *v1);
t_pos *vectorNew(double x, double y, double z);
t_pos *rotation(t_pos *axe, t_pos *vect);

// PARSER
t_tool      *parser(int fd);

void    parse_light(t_tool *tools, int fd);
void    parse_object(t_tool *tools, int fd);
void    parse_camera(t_tool *tools, int fd);

void    add_object(t_object **l_objects, t_object *new);
void    add_light(t_light **l_lights, t_light *new);

int     object_type(char **split);
t_pos   *fill_pos(char **split);
t_color *fill_color(char **split);

// COLOR
t_color *new_color();
void    init_color(t_tool *t, t_color *objcolor, t_color *final_color);
void    normalize_color(t_color *final_color);
void    add_color(t_color *color1, t_color *color2);
void    div_color(t_color *color, float n);

// ERROR
void	ft_error(int i);

// INIT
void	init_camera(t_tool *tools);
void	init_light(t_light *light);
void	init_object(t_object *object);

#endif
