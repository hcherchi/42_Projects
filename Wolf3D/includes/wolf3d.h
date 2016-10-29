/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:29 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:05:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / (double)180)
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define LIM 1000
#define NORTH 0xFFDAB9
#define SOUTH 0xD2691E
#define EAST 0xFF0000
#define WEST 0x00FF00

typedef struct	s_point
{
	double		x;
	double		y;
}								t_point;

typedef struct	s_tool
{
	int fd;
	int nbcol;
	int nbline;
	int		color;
	int		**grid;
	t_point *pos;
	double		angle;
	int			cubeSize;
	int		FOV;
	int		screenWidth;
	int		screenHeight;
	int		centerX;
	int	centerY;
	double		dist;
	double		incAngle;
	void *mlx_ptr;
	void *mlx_win;
	void *mlx_img;
	int			bpp;
	int			endian;
	int			size_line;
}				t_tool;

t_point *getVertical(t_tool *t, double rayAngle);
t_point *getFirstPointVertical(t_tool *t, double rayAngle);
t_point *getNextPointVertical(t_tool *t, t_point *curPoint, t_point *inc);

t_point *getHorizontal(t_tool *t, double rayAngle);
t_point *getFirstPointHorizontal(t_tool *t, double rayAngle);
t_point *getNextPointHorizontal(t_tool *t, t_point *curPoint, t_point *inc);

int getWallHeight(int col, t_tool *t);

double getDist(t_point *wall, t_tool *t);
int   isWall(t_point *intersection, t_tool *t);
int   insideMap(t_point *intersection, t_tool *t);
void	pixel_put_to_image(int color, t_tool *t, int x, int y);
double adjustAngle(double angle, double inc);

void drawCol(int wallHeight, int col, t_tool *t);
void launch(t_tool *tools);
int		keyPress(int key, t_tool *tools);
void  init(t_tool *t);
int		checkGrid(t_tool *tools, char *filename);
int		checkDigit(char **split);
void readGrid(char *file, t_tool *t);

#endif
