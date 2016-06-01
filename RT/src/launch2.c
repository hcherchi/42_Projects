/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:48:42 by bgantelm          #+#    #+#             */
/*   Updated: 2016/06/01 10:48:43 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	run_through(t_tool *t)
{
	int x;
	int y;

	y = 0;
	if (t->rt->screenshot == 0)
		mlx_string_put(t->mlx_ptr, t->rt->mlx_win, t->rt->x_res / 2
				- 50, t->rt->y_res / 2, 0xFFFFFFFF, "RT is loading...");
	mlx_put_image_to_window(t->mlx_ptr, t->rt->mlx_win,
			t->rt->image->mlx_img, 0, 0);
	while (y < t->rt->y_res)
	{
		x = 0;
		while (x < t->rt->x_res)
		{
			draw(t, x, y);
			x += 1;
		}
		y += 1;
	}
	if (t->rt->screenshot == 0)
		mlx_put_image_to_window(t->mlx_ptr, t->rt->mlx_win,
				t->rt->image->mlx_img, 0, 0);
	else
		put_image_to_file(t);
	run_through_tools(t);
}

void	new_cam_upleft(t_cam *cam, t_tool *t)
{
	cam->upleft = malloc(sizeof(t_pos));
	cam->upleft->x = cam->pos->x + cam->vect->x * t->rt->dist +
		cam->h_vect->x * (t->rt->h / 2) - cam->r_vect->x * (t->rt->w / 2);
	cam->upleft->y = cam->pos->y + cam->vect->y * t->rt->dist +
		cam->h_vect->y * (t->rt->h / 2) - cam->r_vect->y * (t->rt->w / 2);
	cam->upleft->z = cam->pos->z + cam->vect->z * t->rt->dist +
		cam->h_vect->z * (t->rt->h / 2) - cam->r_vect->z * (t->rt->w / 2);
}

t_cam	*new_cam(t_pos *pos, t_pos *vect, t_tool *t, int nb)
{
	t_cam	*cam;

	vectornorm(vect);
	cam = malloc(sizeof(t_cam));
	cam->vect = vect;
	cam->pos = pos;
	cam->r_vect = malloc(sizeof(t_pos));
	cam->r_vect->x = cam->vect->z;
	cam->r_vect->y = 0;
	cam->r_vect->z = -1 * cam->vect->x;
	if (cam->vect->x == 0 && cam->vect->z == 0)
		cam->r_vect->x = 1;
	cam->h_vect = malloc(sizeof(t_pos));
	cam->h_vect->x = -cam->r_vect->y * cam->vect->z
		+ cam->r_vect->z * cam->vect->y;
	cam->h_vect->y = -cam->r_vect->z * cam->vect->x
		+ cam->r_vect->x * cam->vect->z;
	cam->h_vect->z = -cam->r_vect->x * cam->vect->y
		+ cam->r_vect->y * cam->vect->x;
	vectornorm(cam->r_vect);
	vectornorm(cam->h_vect);
	new_cam_upleft(cam, t);
	cam->nb = nb;
	return (cam);
}
