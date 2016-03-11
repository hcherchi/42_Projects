
#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include "libft.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct  s_pos
{
    float       x;
    float       y;
    float       z;
}               t_pos;

typedef struct  s_ray
{
    t_pos       O;
    t_pos       D;
}               t_ray;

typedef struct  s_plan
{
    float       a;
    float       b;
    float       c;
    float       d;
}               t_plan;

typedef struct  s_sphere
{
    t_pos       O;
    float       rad;
}               t_sphere;

typedef struct  s_cone
{
    t_pos       O;
    float       h;
    float       rad;
}               t_cone;

typedef struct s_cyl
{
	t_ray		vect;
	float		rad;	
}				t_cyl;

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
}				t_tool;

int     intersection_plan(t_plan plan, t_ray ray, float *coef);
int     intersection_sphere(t_sphere sphere, t_ray ray, float *coef);
int     intersection_cone(t_cone cone, t_ray ray, float *coef);
int     intersection_cyl(t_cyl cyl, t_ray ray, float *coef);


void	pixel_put_to_image(t_tool *t, int x, int y, float r, float g, float b);
t_ray  get_ray(t_tool *t, float x, float y);
void    draw(t_tool *t, float x, float y);

void vectorNorm(t_pos *v);
t_pos vectorMul(t_pos *v1, t_pos *v2);
t_pos vectorSub(t_pos *v1, t_pos *v2);
float vectorDot(t_pos *v1, t_pos *v2);
t_pos vectorScale(float c, t_pos *v);
t_pos vectorAdd(t_pos *v1, t_pos *v2);

#endif
