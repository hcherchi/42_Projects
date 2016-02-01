/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:29 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:05:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct	s_math
{
	int dx;
	int dy;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
}				t_math;

typedef	struct	s_point
{
	int x;
	int	y;
	int z;
}				t_point;

typedef struct	s_tool
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			nbline;
	int			nbcol;
	int			fd;
	int			**tab;
	t_point		***points;
	int			hwin;
	int			wwin;
	t_point		*wmax;
	t_point		*wmin;
	t_point		*hmax;
	t_point		*hmin;
	int			zmin;
	int			zmax;
	float		coef_alti;
}				t_tool;

int				choose_color(t_tool *tools, t_point *a, t_point *b);
void			horizontal_case(t_math *m, t_tool *tools, int color);
void			vertical_case(t_math *m, t_tool *tools, int color);
t_point			*create_point(t_tool *tools, int i, int j);
void			set_points(t_tool *tools);
void			print_grid(t_tool *tools);
void			find_min_max(t_tool *tools);
void			convert_line(int i, t_tool *tools);
void			launch_fdf(t_tool *tools);
int				check_error(char **split);
int				fill_tools(t_tool *tools, char *filename);
void			draw_line(t_point *a, t_point *b, t_tool *tools);
int				tablen(char **tab);
#endif
