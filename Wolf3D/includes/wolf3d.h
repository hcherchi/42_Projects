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

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180)
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define LIM 1000
#define NORTH 0x8B4513
#define SOUTH 0xCD853F
#define EAST 0xA0522D
#define WEST 0xD2691E
#define SKY 0x48D1CC
#define GROUND 0x6B8E23
#define E 0.0001

typedef struct	s_point
{
	float		x;
	float		y;
}								t_point;

typedef struct	s_tool
{
	int		fd;
	int nbcol;
	int nbline;
	int		color;
	int		**grid;
	t_point *pos;
	float		angle;
	int			cubeSize;
	int		FOV;
	int		screenWidth;
	int		screenHeight;
	int		centerX;
	int		centerY;
	float		dist;
	float		incAngle;
	void *mlx_ptr;
	void *mlx_win;
	void *mlx_img;
	int			bpp;
	int			endian;
	int			size_line;
}				t_tool;

t_point *getVertical(t_tool *t, float rayAngle);
t_point *getFirstPointVertical(t_tool *t, float rayAngle);
t_point *getNextPointVertical(t_tool *t, t_point *curPoint, t_point *inc);

t_point *getHorizontal(t_tool *t, float rayAngle);
t_point *getFirstPointHorizontal(t_tool *t, float rayAngle);
t_point *getNextPointHorizontal(t_tool *t, t_point *curPoint, t_point *inc);

int getWallHeight(int col, t_tool *t);

float getDist(t_point *wall, t_tool *t);
int   isWall(t_point *intersection, t_tool *t, float rayAngle);
int   insideMap(t_point *intersection, t_tool *t, float rayAngle);
void	pixel_put_to_image(int color, t_tool *t, int x, int y);
float adjustAngle(float angle, float inc);
int   isUpPart(float angle);
int isRightPart(float angle);

void drawCol(int wallHeight, int col, t_tool *t);
void launch(t_tool *tools);
int		keyPress(int key, t_tool *tools);
void  init(t_tool *t);
int		checkGrid(t_tool *tools, char *filename);
int		checkDigit(char **split);
void readGrid(char *file, t_tool *t);

#endif
