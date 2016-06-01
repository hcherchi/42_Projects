/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:56:14 by hcherchi          #+#    #+#             */
/*   Updated: 2016/06/01 11:33:40 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <libft.h>
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define SPHERE 0
# define CYL 1
# define CONE 2
# define PLAN 3
# define PARA 4
# define SPOT 4
# define SUN  5
# define LIGHTPLAN 6
# define E 0.000001

typedef struct		s_equation
{
	double			a;
	double			b;
	double			c;
	double			discr;
	double			t1;
	double			t0;
}					t_equation;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_colors
{
	t_color			*reflect;
	t_color			*base;
	t_color			*refract;
}					t_colors;

typedef struct		s_k
{
	double			intens;
	double			s;
	double			diff;
}					t_k;

typedef struct		s_pos
{
	double			x;
	double			y;
	double			z;
}					t_pos;

typedef struct		s_image
{
	char			*texture;
	void			*mlx_img;
	unsigned char	*screen;
	int				endian;
	int				size_line;
	int				bpp;
	char			*data;
	int				width;
	int				height;
}					t_image;

typedef struct		s_object
{
	int				type;
	double			dist;
	t_color			*color;
	t_pos			*o;
	t_pos			*d;
	t_image			*texture;
	double			texture_zoom;
	double			rad;
	double			h;
	double			shiny;
	double			mirror;
	double			transp;
	double			refract;
	struct s_object	*next;
}					t_object;

typedef struct		s_ray
{
	t_pos			*o;
	t_pos			*d;
}					t_ray;

typedef struct		s_light
{
	int				type;
	t_pos			*o;
	t_pos			*d;
	t_color			*color;
	double			lumdiff;
	double			angle;
	double			h;
	struct s_light	*next;
}					t_light;

typedef struct		s_cam
{
	t_pos			*pos;
	t_pos			*h_vect;
	t_pos			*r_vect;
	t_pos			*vect;
	t_pos			*upleft;
	int				nb;
}					t_cam;

typedef struct		s_menu
{
	void			*mlx_win;
	t_image			*bg;
	int				x_res;
	int				y_res;
	int				menu;
}					t_menu;

typedef struct		s_rt
{
	void			*mlx_win;
	t_object		*l_objects;
	t_light			*l_lights;
	t_image			*image;
	t_image			*sky;
	t_cam			*cam;
	t_cam			**up;
	t_cam			**mid;
	double			lumamb;
	int				depth;
	double			dist;
	double			w;
	double			h;
	int				x_res;
	int				y_res;
	double			indent;
	t_pos			*pos;
	t_pos			*vect;
	int				error;
	int				screenshot;
	int				sepia;
}					t_rt;

typedef struct		s_double
{
	double			x;
	double			y;
	double			tmp;
	double			div;
	t_color			*color;
}					t_double;

typedef struct		s_tool
{
	void			*mlx_ptr;
	t_rt			*rt;
	t_menu			*m;
	int				m_load_cursor;
	int				error;
}					t_tool;

void				launch(char *scene, t_tool *tools);
void				init_param(t_tool *t);
void				init_cams(t_tool *t);
void				put_image_to_file(t_tool *t);
void				run_through_tools(t_tool *t);
void				run_through(t_tool *t);
void				new_cam_upleft(t_cam *cam, t_tool *t);
t_cam				*new_cam(t_pos *pos, t_pos *vect, t_tool *t, int nb);
double				minimum(t_object *l_objects);
void				fill_dist(t_object *l_objects, t_ray *ray);
double				calcul_cone(t_object *cone, t_ray *ray,
					double k, t_pos *tmp);
t_object			*intersection(t_object *l_objects, t_ray *ray);
double				intersection_plan(t_pos *dir, double h, t_pos *oray,
					t_pos *dray);
double				intersection_sphere(t_object *sphere, t_ray *ray);
double				intersection_cone(t_object *cone, t_ray *ray);
double				intersection_cyl(t_object *cyl, t_ray *ray);
double				intersection_para(t_object *para, t_ray *ray);
void				get_para_normal(t_ray *impact, t_object *object);
void				draw(t_tool *t, int x, int y);
void				pixel_put_to_image(t_tool *t, int x, int y,
					t_color *color);
t_color				*get_color(t_ray *ray, t_tool *t);
void				get_base_color(t_tool *t, t_object *obj, t_ray *impact,
					t_colors *colors);
t_color				*get_final_color(t_colors *colors, t_object *object);
t_color				*get_texture_color(t_object *object, t_ray *impact,
					t_tool *t);
t_color				*extract_color(t_tool *t, t_image *texture, int x, int y);
void				texture_suite(t_double *deux, t_object *object);
t_ray				*get_normal(t_object *object, t_ray *ray);
void				get_cyl_normal(t_ray *impact, t_object *object);
void				get_cone_normal(t_ray *impact, t_object *object);
double				get_kspec(t_ray *lightray, t_ray *impact, double intens);
double				get_kdiff(t_ray *lightray, t_ray *impact, double intens);
void				update_color(double k, t_color *lightcolor,
					t_color *final_color, t_color *objcolor);
t_color				*get_flash(t_ray *ray, t_tool *t);
t_ray				*get_lightray(t_ray *impact, t_light *light);
t_ray				*get_ray(t_tool *t, double x, double y);
t_ray				*get_reflectray(t_ray *ray, t_tool *t, t_ray *impact);
t_ray				*get_refractray(t_ray *ray, t_ray *impact,
					t_object *object);
t_pos				*v(t_pos *v1, t_pos *v2);
void				vectornorm(t_pos *v);
t_pos				*vectorsub(t_pos *v1, t_pos *v2);
double				vectordot(t_pos *v1, t_pos *v2);
t_pos				*vectorscale(double c, t_pos *v);
t_pos				*vectoradd(t_pos *v1, t_pos *v2);
t_pos				*vectorcopy(t_pos *v1);
t_pos				*vectornew(double x, double y, double z);
t_pos				*rotation(t_pos *axe, t_pos *vect);
void				suite_parse_object2(char **split, t_tool *tools,
					t_object *object);
void				suite_parse_object4(char **split, t_tool *tools,
					t_object *object);
void				suite_parse_object3(char **split, t_tool *tools,
					t_object *object);
void				suite_parse_object(t_tool *tools, char *line,
					char **split, t_object *object);
void				parser(int fd, t_tool *tools);
void				parse_light(t_tool *tools, int fd);
void				parse_light2(char *line, t_light *light,
					char **split, t_tool *tools);
void				parse_light3(char *line, t_light *light,
					char **split, t_tool *tools);
void				parse_object(t_tool *tools, int fd);
void				parse_object2(char *line, t_object *object,
					char **split, t_tool *tools);
void				parse_object3(char *line, t_object *object,
					char **split, t_tool *tools);
void				parse_object4(char *line, t_object *object,
					char **split, t_tool *tools);
void				parse_camera(t_tool *tools, int fd);
void				parse_camera2(char *line, t_tool *tools, char **split);
void				init_light(t_light *light);
void				init_object(t_object *object);
void				init_camera(t_tool *tools);
void				add_object(t_object **l_objects, t_object *new);
void				add_light(t_light **l_lights, t_light *new);
int					object_type(char **split, t_tool *tools);
int					light_type(char **split, t_tool *tools);
t_pos				*fill_pos(char **split, t_tool *tools);
t_color				*fill_color(char **split, t_tool *tools);
t_image				*fill_texture(char *file, t_tool *tools);
t_color				*new_color();
t_colors			*new_colors();
void				normalize_color(t_color *final_color);
t_color				*add_color(t_color *color1, t_color *color2);
t_color				*div_color(t_color *color, double n);
t_color				*mult_color(t_color *color, double n);
void				ft_error();
void				ft_error_suite();
void				run_through(t_tool *t);
void				launch(char *scene, t_tool *tools);
void				init_param(t_tool *t);
t_cam				*new_cam(t_pos *pos, t_pos *vect, t_tool *t, int nb);
void				init_cams(t_tool *t);
int					rt_event(int keycode, t_tool *t);
void				clean_ray(t_ray **ray);
void				clean_obj(t_object **l_objects);
void				clean_lights(t_light **l_lights);
void				clean_cam(t_cam **cam);
void				clean_tools(t_tool **tools);
void				clean_colors(t_colors **colors);
void				clean_cams(t_cam ***cams, int nb);
void				clean_image(t_image **image);
void				clean_tab(char **tab);
void				clean_menu(t_menu **m);
void				clean_rt(t_rt **rt);
void				print_groupe1(t_tool *t);
int					ft_verif(t_tool *t, char *verife);
void				print_suite(t_tool *t);
int					ft_exit2(t_tool *t);
int					ft_exit(t_tool *t);
int					mouse_event(int x, int y, int keycode, t_tool *t);
int					mouse_event_rt(int x, int y, int keycode, t_tool *t);
void				mouse_event_rt2(int x, int y, t_tool *t);
void				mouse_event2(int x, int y, t_tool *t);
void				init_menu(t_tool *tools);
void				main_menu(int i);
void				print_scene_menu(t_tool *t);
void				print_build_menu(t_tool *t);
void				print_group_menu(t_tool *t);
void				print_start_menu(t_tool *t);
int					menu_event(int keycode, t_tool *t);
int					ft_menu_mouse_handler(int x, int y, void *param);
int					ft_menu_click_handler(int keycode, int x, int y, t_tool *t);
void				scene_menu(int keycode, t_tool *t);
void				modif_all_lights(t_tool *k, double value);
void				modif_lumamb(t_tool *k, double value);
void				update_loading_menu(t_tool *t, int y);

#endif
