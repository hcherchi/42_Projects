/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:38:33 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 16:10:03 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		event(int keycode, t_tool *t)
{
	if (keycode == 53 && t)
	{
		clean_tools(t);
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125)
		change_pos(keycode, t);
	return (0);
}

void	change_pos(int keycode, t_tool *t)
{
	if (keycode == 123 || keycode == 124 || keycode == 125)
	{
		free(t->cam->vect);
		free(t->cam->pos);
		if (keycode == 123)
		{
			t->cam->vect = vectornew(1, 0, 0);
			t->cam->pos = vectornew(-5, 0, 4);
		}
		else if (keycode == 124)
		{
			t->cam->vect = vectornew(-1, 0, 0);
			t->cam->pos = vectornew(5, 0, 4);
		}
		else if (keycode == 125)
		{
			t->cam->vect = vectornew(0, 0, 1);
			t->cam->pos = vectornew(0, 0, 0);
		}
		vectornorm(t->cam->vect);
		run_through(t);
	}
}
