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
#define E -0.00001

typedef struct s_k
{
    float      spec;
    float      diff;
    float      dist;
}               t_k;

typedef struct s_equation
{
	float      a;
	float      b;
	float      c;
	float      discr;
	float      t1;
	float      t0;
}               t_equation;

typedef struct s_color
{
	int       r;
	int       g;
	int       b;
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
	t_color     *color;
	t_pos       *O;
	t_pos       *D;
	float               rad;
	float               h;
	float                shiny;
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
	float           dist;
    float           LumDiff;
	struct s_light  *next;
}              t_light;

typedef struct  s_cam
{
	t_pos       *pos;
	t_pos       *h_vect;
	t_pos       *r_vect;
	t_pos       *vect;
	float       dist;
	float       W;
	float       H;
	t_pos       *upleft;
	int       x_res;
	int       y_res;
	float       indent;
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
	float       LumAmb;
}				t_tool;

// INTERSECTIONS
t_object    *intersection(t_object *l_objects, t_ray *ray);
float     intersection_plan(t_object *plan, t_ray *ray);
float     intersection_sphere(t_object *sphere, t_ray *ray);
float     intersection_cone(t_object *cone, t_ray *ray);
float     intersection_cyl(t_object *cyl, t_ray *ray);


// DESSIN
void    draw(t_tool *t, int x, int y);
t_ray  *get_ray(t_tool *t, float x, float y);
t_color   *get_color(t_ray *ray ,t_tool *t);
t_ray    *get_normal(t_object *object, t_ray *ray);
t_ray   *get_lightray(t_ray *impact, t_light *curLight);
void    illuminate(t_tool *t, t_object *curObject, t_ray *impact, t_color *final_color);
float  get_kspec(t_ray *lightray, t_ray *impact);
float  get_kdiff(t_ray *lightray, t_ray *impact);
void update_color(float k, t_color *lightcolor, t_color *final_color, t_color *objcolor);
void	pixel_put_to_image(t_tool *t, int x, int y, t_color *color);

// VECTOR
void vectorNorm(t_pos *v);
t_pos *vectorSub(t_pos *v1, t_pos *v2);
float vectorDot(t_pos *v1, t_pos *v2);
t_pos *vectorScale(float c, t_pos *v);
t_pos *vectorAdd(t_pos *v1, t_pos *v2);
t_pos *vectorCopy(t_pos *v1);
t_pos *vectorNew(float x, float y, float z);
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

void    update_cam(t_tool *t);
void	run_through(t_tool *t);
void    init_param(t_tool *t);
int		event(int keycode, t_tool *t);

#endif
