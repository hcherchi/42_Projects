/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/12/04 12:55:07 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	adjust_angle(float angle, float inc)
{
	if (angle + inc >= 360)
		angle = angle + inc - 360;
	else if (angle + inc < 0)
		angle = angle + inc + 360;
	else
		angle = angle + inc;
	return (angle);
}

void	handle_move(t_tool *tools, int speed)
{
	t_point	*new_pos;

	new_pos = malloc(sizeof(*new_pos));
	new_pos->x = tools->pos->x + cos(D_TO_R(tools->angle)) * speed;
	new_pos->y = tools->pos->y - sin(D_TO_R(tools->angle)) * speed;
	if (inside_map(new_pos, tools) && is_wall(new_pos, tools) == 0)
	{
		free(tools->pos);
		tools->pos = new_pos;
		launch(tools);
	}
	else
		free(new_pos);
}

int		key_press(int key, t_tool *tools)
{
	if (key == 53)
	{
		clean(tools);
		exit(0);
	}
	else if (key == 123 || key == 124)
	{
		if (key == 123)
			tools->angle = adjust_angle(tools->angle, 10);
		else if (key == 124)
			tools->angle = adjust_angle(tools->angle, -10);
		launch(tools);
	}
	else if (key == 126)
		handle_move(tools, 20);
	else if (key == 125)
		handle_move(tools, -20);
	return (0);
}
