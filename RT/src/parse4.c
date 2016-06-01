/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 10:48:55 by bgantelm          #+#    #+#             */
/*   Updated: 2016/06/01 10:48:57 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_image		*fill_texture(char *file, t_tool *t)
{
	t_image *texture;

	texture = malloc(sizeof(t_image));
	texture->texture = ft_strdup(file);
	texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr,
			texture->texture, &texture->width, &texture->height);
	if (texture->mlx_img == NULL)
	{
		ft_error(11, t);
		return (NULL);
	}
	texture->data = mlx_get_data_addr(texture->mlx_img,
			&texture->bpp, &texture->size_line, &texture->endian);
	texture->screen = NULL;
	return (texture);
}

void		suite_parse_object(t_tool *t, char *line, char **split, t_object *o)
{
	split = ft_strsplit(line, ' ');
	if (ft_strstr(line, "type:"))
		o->type = object_type(split, t);
	else if (ft_strstr(line, "rayon:"))
	{
		if (ft_tablen(split) == 2)
		{
			if (str_digit(split[1]))
				ft_error(2, t);
			o->rad = ft_atof(split[1]);
		}
		else
			ft_error(7, t);
	}
	else
		parse_object2(line, o, split, t);
	if (o->mirror + o->transp > 1)
		ft_error(15, t);
	clean_tab(split);
	free(line);
}

void		suite_parse_object2(char **split, t_tool *tools, t_object *o)
{
	if (ft_tablen(split) == 2)
	{
		if (str_digit(split[1]))
			ft_error(2, tools);
		if (ft_atof(split[1]) > 1 || ft_atof(split[1]) < 0)
			ft_error(14, tools);
		o->mirror = ft_atof(split[1]);
	}
	else
		ft_error(7, tools);
}

void		suite_parse_object3(char **split, t_tool *tools, t_object *o)
{
	if (ft_tablen(split) == 2)
	{
		if (str_digit(split[1]))
			ft_error(2, tools);
		o->refract = ft_atof(split[1]);
	}
	else
		ft_error(7, tools);
}

void		suite_parse_object4(char **split, t_tool *tools, t_object *object)
{
	if (ft_tablen(split) == 3)
	{
		object->texture = fill_texture(split[1], tools);
		if (str_digit(split[2]))
			ft_error(2, tools);
		object->texture_zoom = ft_atof(split[2]);
	}
	else
		ft_error(7, tools);
}
