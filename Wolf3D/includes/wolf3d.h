/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:29 by hcherchi          #+#    #+#             */
/*   Updated: 2016/12/04 13:36:08 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define D_TO_R(angle_degrees) (angle_degrees * M_PI / 180)
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

# define LIM 1000
# define E 0.001

# define NORTH 0x8B4513
# define SOUTH 0xCD853F
# define EAST 0xA0522D
# define WEST 0xD2691E
# define SKY 0x48D1CC
# define GROUND 0x6B8E23

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_tool
{
	int			fd;
	int			nbcol;
	int			nbline;
	int			color;
	int			**grid;
	t_point		*pos;
	float		angle;
	int			cube;
	int			fov;
	int			width;
	int			height;
	int			center_x;
	int			center_y;
	float		dist;
	float		inc_angle;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	int			bpp;
	int			endian;
	int			size_line;
}				t_tool;

float			get_vertical_dist(t_tool *t, float ray_angle);
t_point			*get_first_point_vertical(t_tool *t, float ray_angle);
t_point			*get_next_point_vertical(t_tool *t, t_point *cur, t_point *inc);

float			get_horizontal_dist(t_tool *t, float ray_angle);
t_point			*get_first_point_horizontal(t_tool *t, float ray_angle);
t_point			*get_next_point_horizontal(t_tool *t, t_point *c, t_point *in);

void			draw_col(int wall_height, int col, t_tool *t);
void			launch(t_tool *tools);
void			pixel_put_to_image(int color, t_tool *t, int x, int y);
int				get_wall_height(int col, t_tool *t);
int				get_wall_color(float horiz, float vert, float dist, float ray);

float			get_dist(t_point *wall, t_tool *t);
int				is_wall(t_point *intersection, t_tool *t);
int				inside_map(t_point *intersection, t_tool *t);
int				is_up_part(float angle);
int				is_right_part(float angle);

int				key_press(int key, t_tool *tools);
float			adjust_angle(float angle, float inc);

void			init(t_tool *t);
int				check_grid(t_tool *tools, int fd);
int				check_digit(char **split);
void			read_grid(t_tool *t, int fd);

void			clean(t_tool *tools);
void			clean_tab(char **tab);

#endif
