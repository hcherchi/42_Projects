/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float adjustAngle(float angle, float inc)
{
	if (angle + inc >= 360)
		angle = angle + inc - 360;
	else if (angle + inc < 0)
		angle = angle + inc + 360;
	else
		angle = angle + inc;
	return angle;
}

void handleMove(t_tool *tools, int speed)
{
  t_point *newPos;

  newPos = malloc(sizeof(*newPos));
  newPos->x = tools->pos->x + cos(degreesToRadians(tools->angle)) * speed;
  newPos->y = tools->pos->y - sin(degreesToRadians(tools->angle)) * speed;
  if (insideMap(newPos, tools) && isWall(newPos, tools) == 0)
  {
    free(tools->pos);
    tools->pos = newPos;
    launch(tools);
  }
  else
    free(newPos);
}

int		keyPress(int key, t_tool *tools)
{
	if (key == 53)
  {
    clean(tools);
		exit(0);
  }
  else if (key == 123 || key == 124)
  {
  	if (key == 123)
  		tools->angle = adjustAngle(tools->angle, 10);
  	else if (key == 124)
  		tools->angle = adjustAngle(tools->angle, -10);
    launch(tools);
  }
  else if (key == 126)
    handleMove(tools, 20);
	else if (key == 125)
    handleMove(tools, -20);
	return (0);
}
