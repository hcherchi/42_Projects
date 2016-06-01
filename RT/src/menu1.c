/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:49:51 by fhenri            #+#    #+#             */
/*   Updated: 2016/06/01 14:49:26 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	print_groupe2(t_tool *t)
{
	ft_verif(t, ft_strdup("miniature/fhenri.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/fhenri.xpm"),
	&t->m->bg->width, &t->m->bg->height), 160, 780);
	ft_verif(t, ft_strdup("miniature/go_back.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/go_back.xpm"),
	&t->m->bg->width, &t->m->bg->height), 100, 910);
	ft_verif(t, ft_strdup("miniature/copy.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/copy.xpm"),
	&t->m->bg->width, &t->m->bg->height), 150, 1000);
}

void	print_groupe1(t_tool *t)
{
	ft_verif(t, ft_strdup("miniature/logo_rt.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/logo_rt.xpm"),
	&t->m->bg->width, &t->m->bg->height), 100, 10);
	ft_verif(t, ft_strdup("miniature/hcherchi.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/hcherchi.xpm"),
	&t->m->bg->width, &t->m->bg->height), 160, 180);
	ft_verif(t, ft_strdup("miniature/bgantelm.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/bgantelm.xpm"),
	&t->m->bg->width, &t->m->bg->height), 160, 380);
	ft_verif(t, ft_strdup("miniature/vnguyen.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/vnguyen.xpm"),
	&t->m->bg->width, &t->m->bg->height), 160, 580);
	print_groupe2(t);
}

void	print_suite2(t_tool *t)
{
	ft_verif(t, ft_strdup("miniature/all.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/all.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 710);
	ft_verif(t, ft_strdup("miniature/alpe.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/alpe.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 710);
	ft_verif(t, ft_strdup("miniature/poke.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/poke.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 850);
	ft_verif(t, ft_strdup("miniature/grasse.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/grasse.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 850);
	ft_verif(t, ft_strdup("miniature/42.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/42.xpm"),
	&t->m->bg->width, &t->m->bg->height), 250, 980);
	ft_verif(t, ft_strdup("miniature/youtube.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/youtube.xpm"),
	&t->m->bg->width, &t->m->bg->height), 210, 1000);
}

void	print_suite1(t_tool *t)
{
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr,
	ft_strdup("miniature/space-cylinder.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 290);
	ft_verif(t, ft_strdup("miniature/blackhole.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/blackhole.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 430);
	ft_verif(t, ft_strdup("miniature/bruno.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/bruno.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 430);
	ft_verif(t, ft_strdup("miniature/pion.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/pion.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 570);
	ft_verif(t, ft_strdup("miniature/solar.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/solar.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 570);
	print_suite2(t);
}

void	print_suite(t_tool *t)
{
	ft_verif(t, ft_strdup("miniature/logo_rt.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/logo_rt.xpm"),
	&t->m->bg->width, &t->m->bg->height), 100, 10);
	ft_verif(t, ft_strdup("miniature/point.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/point.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 980);
	ft_verif(t, ft_strdup("miniature/disco.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/disco.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 150);
	ft_verif(t, ft_strdup("miniature/boat.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/boat.xpm"),
	&t->m->bg->width, &t->m->bg->height), 240, 150);
	ft_verif(t, ft_strdup("miniature/room.xpm"));
	mlx_put_image_to_window(t->mlx_ptr, t->m->mlx_win,
	mlx_xpm_file_to_image(t->mlx_ptr, ft_strdup("miniature/room.xpm"),
	&t->m->bg->width, &t->m->bg->height), 60, 290);
	ft_verif(t, ft_strdup("miniature/space-cylinder.xpm"));
	print_suite1(t);
}
